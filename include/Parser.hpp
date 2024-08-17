#pragma once
#include <string>
#include <memory>
#include <vector>

#include "AST.hpp"
#include "Lexer.hpp"
#include "Tokens.hpp"
#include "ASTCheckVisitor.hpp"
#include "Interpreter.hpp"

class Parser {
public:
	Parser();
	~Parser();

	void parseFile(const std::string& filename);
	void parseString(const std::wstring& input);

	void debugTokens();
private:
	std::wstring m_input;
	std::vector<std::unique_ptr<Token>> m_tokens;
	AST m_ast;
	Lexer m_lexer;
	Interpreter m_interpreter;
	//Visitor m_visitor;
	//std::vector<std::unique_ptr<Scope>> m_scopes;
};