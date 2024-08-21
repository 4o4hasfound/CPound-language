#include "Scope.hpp"

Scope::Scope() {

}

Scope::~Scope() {
	
}

std::shared_ptr<Value> Scope::getVariable(const std::wstring& symbol, int recursiveSearch) {
	if (recursiveSearch) {
		for (auto itr = m_variables.rbegin(), end = m_variables.rend(); itr != end; ++itr) {
			if (itr->count(symbol)) {
				return (*itr)[symbol];
			}
		}
	}
	else if (!m_variables.empty()) {
		if (m_variables.back().count(symbol)) {
			return m_variables.back()[symbol];
		}
	}
	return nullptr;
}

EvaluateVariableDeclarationNode* Scope::getEvaluateVariable(const std::wstring& symbol, int recursiveSearch) {
	if (recursiveSearch) {
		for (auto itr = m_evalVariables.rbegin(), end = m_evalVariables.rend(); itr != end; ++itr) {
			if (itr->count(symbol)) {
				return (*itr)[symbol];
			}
		}
	}
	else if (!m_evalVariables.empty()) {
		if (m_evalVariables.back().count(symbol)) {
			return m_evalVariables.back()[symbol];
		}
	}
	return nullptr;
}

FunctionDeclarationNode* Scope::getFunction(const std::wstring& symbol, const std::vector<std::shared_ptr<Value>>& parameters) {
	if (m_functions.count(symbol)) {
		auto& map = m_functions[symbol];
		std::wstring mangledSymbol = mangleName(symbol, parameters);
		if (map.count(mangledSymbol)) {
			return map[mangledSymbol];
		}
		for (const auto& [string, function] : map) {
			bool cannotConvert = 0;
			for (int i = 0; i < function->declaration.parameters.size(); ++i) {
				VariableDeclarationInfo& funcParam = function->declaration.parameters[i];
				if (i < parameters.size()) {
					if (!canConvert(parameters[i], funcParam.type)
						|| (funcParam.reference &&
							!parameters[i]->copy()->setDeclType(funcParam.declType))
						) {
						cannotConvert = 1;
						break;
					}
				}
				else if (!funcParam.defaultValue) {
					cannotConvert = 1;
					break;
				}
			}
			if (!cannotConvert) {
				return function;
			}
		}
	}
	return nullptr;
}

void Scope::addVariable(const std::wstring& symbol, std::shared_ptr<Value> value) {
	m_variables.back()[symbol] = value;
}

void Scope::addEvalVariable(const std::wstring& symbol, ASTNode* value) {
	m_evalVariables.back()[symbol] = dynamic_cast<EvaluateVariableDeclarationNode*>(value);
}

void Scope::addFunction(FunctionDeclarationNode* info) {
	if (!m_functions.count(info->declaration.symbol)) {
		m_functions[info->declaration.symbol] = std::unordered_map<std::wstring, FunctionDeclarationNode*>();
	}
	m_functions[info->declaration.symbol][info->declaration.mangledSymbol] = info;
}

void Scope::addScope() {
	m_variables.emplace_back();
	m_evalVariables.emplace_back();
}

void Scope::popScope() {
	if (m_variables.size() >= 2) {
		Scope::VariableScope& nextScope = m_variables[m_variables.size() - 2];
		for (auto& [symbol, var] : m_variables.back()) {
			if (var->lifetime.scope > 1) {
				--var->lifetime.scope;
				nextScope[symbol] = std::move(var);
			}
		}
	}
	m_variables.pop_back();
	m_evalVariables.pop_back();
}
