#pragma once
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>

#include "Types.hpp"
#include "Value.hpp"
#include "ASTNodes.hpp"

#include "Utils/typeCasting.hpp"
#include "Utils/nameMangling.hpp"

class Scope {
public:
	Scope();
	~Scope();
	
	std::shared_ptr<Value> getVariable(const std::wstring& symbol, int recursiveSearch = 1);
	EvaluateVariableDeclarationNode* getEvaluateVariable(const std::wstring& symbol, int recursiveSearch = 1);
	FunctionDeclarationNode* getFunction(const std::wstring& symbol, const std::vector<std::shared_ptr<Value>>& parameters);

	void addVariable(const std::wstring& symbol, std::shared_ptr<Value> value);
	void addEvalVariable(const std::wstring& symbol, ASTNode* value);
	void addFunction(FunctionDeclarationNode* info);

	void addScope();
	void popScope();
private:

	// unmangled -> map of mangled name
	// Example:
	// function add(var int) var int;		-> unmangled name: add ; mangled name: add@int_
	// function add(var float) var float;	-> unmangled name: add ; mangled name: add@float_
	std::unordered_map<std::wstring, std::unordered_map<std::wstring, FunctionDeclarationNode*>> m_functions;

	using VariableScope = std::unordered_map<std::wstring, std::shared_ptr<Value>>;
	std::vector<VariableScope> m_variables;

	std::vector<std::unordered_map<std::wstring, EvaluateVariableDeclarationNode*>> m_evalVariables;
};
