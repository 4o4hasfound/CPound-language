#include "Tokens/IdentifierToken.hpp"

std::wregex IdentifierToken::s_regex = IdentifierToken::compileRegex();

IdentifierToken::IdentifierToken(const std::wstring& string, std::wstring::const_iterator pos)
	: Token(Token::Identifier, pos)
	, identifierName(string) {

}

std::wstring IdentifierToken::str() const {
	return identifierName;
}

std::unique_ptr<Token> IdentifierToken::getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, Token* previousToken) {
	std::wsmatch match;
	if (std::regex_search(start, end, match, s_regex)) {
		if (start != match.prefix().second) {
			return nullptr;
		}
		auto ptr = std::make_unique<IdentifierToken>(match[0], start);
		start = match.suffix().first;
		return ptr;
	}
	return nullptr;
}

std::wregex IdentifierToken::compileRegex() {
	return generateRegex({ LR"([a-zA-Z]([a-zA-Z0-9_]*))" }, 0);
}
