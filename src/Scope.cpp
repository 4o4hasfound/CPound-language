#include "Scope.hpp"

Scope::Scope() {

}

Scope::~Scope() {
	
}

std::shared_ptr<Value> Scope::getVariable(const std::wstring& symbol, int recursiveSearch) {
	std::shared_ptr<Value> value = nullptr;
	auto itr = m_variables.rbegin();
	if (recursiveSearch) {
		for (auto end = m_variables.rend(); itr != end; ++itr) {
			if (itr->count(symbol)) {
				value = (*itr)[symbol];
				break;
			}
		}
	}
	else if (!m_variables.empty()) {
		if (m_variables.back().count(symbol)) {
			value = m_variables.back()[symbol];
		}
	}
	if (m_toDestroy[value.get()]) {
		return nullptr;
	}
	return value;
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
 
void Scope::addVariable(const std::wstring& symbol, const std::shared_ptr<Value>& value) {
	m_variables.back()[symbol] = value;
	m_variableExistsInScope.back()[value.get()] = true;
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
	m_variableExistsInScope.emplace_back();
	m_evalVariables.emplace_back();
}

void Scope::popScope() {
	m_variableExistsInScope.pop_back();
	if (m_variables.size() >= 2) {
		Scope::VariableScope& nextScope = m_variables[m_variables.size() - 2];
		for (auto& [symbol, var] : m_variables.back()) {
			if (!m_toDestroy[var.get()] && var->lifetime.scope > 1) {
				--var->lifetime.scope;
				m_toDestroy.erase(var.get());
				nextScope[symbol] = std::move(var);
				if (!m_variableExistsInScope.empty()) {
					m_variableExistsInScope.back()[var.get()] = 1;
				}
			}
		}
	}
	m_variables.pop_back();
	m_evalVariables.pop_back();
}

void Scope::cleanVariable(ASTNode* node) {
	for (auto& [symbol, variable] : m_variables.back()) {
		if (m_toDestroy[variable.get()]) {
			continue;
		}
		if (variable->reference) {
			if (!m_variableExistsInScope.back().count(variable.get())) {
				if (!variable->getReferenceObject()->isValidTime()) {
					std::shared_ptr<Value> value = variable->getReferenceObject();
					m_variableExistsInScope.back().erase(value.get());
					m_toDestroy[value.get()] = 1;
				}
			}
			if (!variable->isValid(node)) {
				m_variableExistsInScope.back().erase(variable.get());
				m_toDestroy[variable.get()] = 1;
			}
		}
		else if (!variable->isValid(node)) {
			m_variableExistsInScope.back().erase(variable.get());
			m_toDestroy[variable.get()] = 1;
		}
	}
}
