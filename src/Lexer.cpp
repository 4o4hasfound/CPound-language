#include "Lexer.hpp"

Lexer::Lexer(std::vector<std::unique_ptr<Token>>& tokens)
	: m_tokens(tokens) {

}

void Lexer::tokenize(const std::wstring& input) {
	std::wstring::const_iterator start = input.cbegin(), end = input.cend();

	Token* lastToken = nullptr;
	WhiteSpace::eat(start, end);
	
	while (start != end) {
		std::unique_ptr<Token> ptr = nullptr;

		if ((ptr = TerminatorToken::getToken(start, end, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = StringLiteralToken::getToken(start, end, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = NumericLiteralToken::getToken(start, end, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = BooleanLiteralToken::getToken(start, end, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = LifetimeToken::getToken(start, end, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = OperatorToken::getToken(start, end, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = DelimiterToken::getToken(start, end, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = KeywordToken::getToken(start, end, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = IdentifierToken::getToken(start, end, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else {
			Error::Log(start, L"Invalid character", input);
		}
		lastToken = m_tokens.back().get();
		WhiteSpace::eat(start, end);
	}
}