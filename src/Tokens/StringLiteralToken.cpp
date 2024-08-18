#include "Tokens/StringLiteralToken.hpp"

std::wregex StringLiteralToken::s_regex = compileRegex();

StringLiteralToken::StringLiteralToken(const std::wstring& value, std::wstring::const_iterator pos)
	: Token(TokenType::StringLiteral, pos)
	, literalValue(std::regex_replace(value, std::wregex(L"\\\\n"), L"\n")) {
}

std::wstring StringLiteralToken::str() const {
	return literalValue;
}

std::unique_ptr<Token> StringLiteralToken::getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, Token* previousToken) {
	std::wsmatch match;
	if (std::regex_search(start, end, match, s_regex)) {
		if (start != match.prefix().second) {
			return nullptr;
		}
		if (match.size() > 2) {
			auto ptr = std::make_unique<StringLiteralToken>(match[2], start);
			start = match.suffix().first;
			return ptr;
		}
		else {
			auto ptr = std::make_unique<StringLiteralToken>(L"", start);
			start = match.suffix().first;
			return ptr;
		}
	}
	return nullptr;
}

std::wregex StringLiteralToken::compileRegex() {
	return generateRegex({ LR"("(.*?)\")" }, 0, L"");
}
