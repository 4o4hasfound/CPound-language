#include "Tokens/KeywordToken.hpp"

std::vector<std::wstring> KeywordToken::s_keywordRegexes{
	L"(var|const)( (var|const)){0,2}",
	L"if",
	L"else",
	L"class",
	L"public",
	L"private",
	L"evaluate",
	L"operator",
	L"typecast",
	L"inherit",
	L"reference",
	L"yoink",
	L"check this out",
	L"what is",
	L"reverse",
	L"noop"
};
std::wregex KeywordToken::s_regex = KeywordToken::compileRegex();
std::wregex KeywordToken::s_functionRegex = generateRegex({ LR"((?=[function]{2,})(f?u?n?c?t?i?o?n?))" }, 0, LR"(^\s:)");

KeywordToken::KeywordToken(KeywordType KeywordType, std::wstring::const_iterator pos)
	: Token(Token::Keyword, static_cast<int>(KeywordType), pos) {

}

std::wstring KeywordToken::str() const {
	return KeywordTypeStringMap[static_cast<KeywordType>(valueType)];
}

std::unique_ptr<Token> KeywordToken::getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, Token* previousToken) {
	std::wsmatch match;
	if (std::regex_search(start, end, match, s_regex)
		&& start == match.prefix().second) {
		auto ptr = std::make_unique<KeywordToken>(KeywordTypeStringMap[match[0]], start);
		start = match.suffix().first;
		return ptr;
	}
	else if (std::regex_search(start, end, match, s_functionRegex)) {
		if (start != match.prefix().second) {
			return nullptr;
		}
		auto ptr = std::make_unique<KeywordToken>(KeywordType::Function, start);
		start = match.suffix().first;
		return ptr;
	}
	return nullptr;
}

std::wregex KeywordToken::compileRegex() {
	return generateRegex(s_keywordRegexes, 0, LR"(^\s:)");
}
