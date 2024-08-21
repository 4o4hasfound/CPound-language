#include "Tokens/DelimiterToken.hpp"

std::vector<std::wstring> DelimiterToken::s_delimiterList{ {
	L"(",
	L")",
	L"[",
	L"]",
	L"{",
	L"}",
	L",",
} };
std::wregex DelimiterToken::s_regex = DelimiterToken::compileRegex();

DelimiterToken::DelimiterToken(DelimiterType delimiterType, std::wstring::const_iterator pos, const std::wstring& string)
	: Token(Token::Delimiter, static_cast<int>(delimiterType), pos, string) {

}

std::wstring DelimiterToken::str() const {
	return delimiterTypeStringMap[static_cast<DelimiterType>(valueType)];
}

std::unique_ptr<Token> DelimiterToken::getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, const std::wstring& string, Token* previousToken) {
	std::wsmatch match;
	if (std::regex_search(start, end, match, s_regex)) {
		if (start != match.prefix().second) {
			return nullptr;;
		}
		auto ptr = std::make_unique<DelimiterToken>(delimiterTypeStringMap[match[0]], start, string);
		start = match.suffix().first;
		return ptr;
	}
	return nullptr;
}

std::wregex DelimiterToken::compileRegex() {
	return generateRegex(s_delimiterList, 1);
}
