#include "Parser.hpp"

Parser::Parser()
	: m_lexer(m_tokens), m_input(), m_ast(m_tokens), m_interpreter(&m_input) {

}

Parser::~Parser() {

}

void Parser::parseFile(const std::string& filename) {
	std::wifstream file;
	file.exceptions(std::ifstream::failbit);
	file.open(filename);

	std::wstringstream wss;
	wss << file.rdbuf();
	m_input = wss.str();
	m_lexer.tokenize(m_input);
	//debugTokens();
	m_ast.build(&m_input);
	auto visitor = std::make_unique<ASTCheckVisitor>(&m_input);
	visitor->visitProgramNode(m_ast.program.get());
	m_interpreter.run(m_ast.program.get());
}

void Parser::parseString(const std::wstring& input) {
	m_input = input;
	m_lexer.tokenize(m_input);
}

void Parser::debugTokens() {
	for (const auto& token : m_tokens) {
		std::wcout << token->str() << "\n";
	}
}
