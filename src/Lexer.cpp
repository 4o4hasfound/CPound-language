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

		if ((ptr = TerminatorToken::getToken(start, end, input, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = StringLiteralToken::getToken(start, end, input, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = NumericLiteralToken::getToken(start, end, input, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = BooleanLiteralToken::getToken(start, end, input, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = LifetimeToken::getToken(start, end, input, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = OperatorToken::getToken(start, end, input, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = DelimiterToken::getToken(start, end, input, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = KeywordToken::getToken(start, end, input, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else if ((ptr = IdentifierToken::getToken(start, end, input, lastToken))) {
			m_tokens.push_back(std::move(ptr));
		}
		else {
			Error::Log(PositionInfo(start, input), L"Invalid character", input);
		}
		lastToken = m_tokens.back().get();
		WhiteSpace::eat(start, end);
	}
}