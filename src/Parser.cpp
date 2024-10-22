#include "Parser.hpp"

Parser::Parser()
	: m_lexer(m_tokens), m_input(), m_ast(m_tokens), m_interpreter(&m_input) {

}

Parser::~Parser() {

}

void Parser::parseFile(const std::wstring& filename) {
	std::wifstream file;
	file.open(filename);
	if (file.fail()) {
		Error::Log(L"Invalid filename!");
	}
	std::wstringstream wss;
	wss << file.rdbuf();
	m_input = wss.str();
	m_lexer.tokenize(m_input);
	
	if (m_tokens.empty()) {
		return;
	}

	m_ast.build(&m_input);
}

void Parser::parseString(const std::wstring& input) {
	m_input = input;
	m_lexer.tokenize(m_input);
}

void Parser::run() {
	m_interpreter.run(m_ast.program.get());
}

void Parser::debugAST() const {
	m_ast.debug();
}
