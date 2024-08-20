#include "Tokens/OperatorToken.hpp"

std::vector<std::wstring> OperatorToken::s_operatorList{ {
	L"[[positive]]"	,
	L"positive"		,
	L"[[negative]]"	,
	L"negative"		,
	L"[[absolute]]"	,
	L"absolute"		,
	L"===="			,
	L"==="			,
	L";=="			,
	L"**="			,
	L"*="			,
	L"+++"			,
	L"++"			,
	L"---"			,
	L"--"			,
	L"<<="			,
	L">>="			,
	L";="			,
	L"&&="			,
	L"||="			,
	L"**"			,
	L"=="			,
	L">="			,
	L"<="			,
	L"&&"			,
	L"||"			,
	L"<<"			,
	L">>"			,
	L"+="			,
	L"-="			,
	L"*="			,
	L"/="			,
	L"%="			,
	L"&="			,
	L"|="			,
	L"^="			,
	L"~="			,
	L"="			,
	L"+"			,
	L"-"			,
	L"*"			,
	L"/"			,
	L"%"			,
	L";"			,
	L"&"			,
	L"|"			,
	L"^"			,
	L"~"			,
	L">"			,
	L"<"			,
} };
std::wregex OperatorToken::s_regex = OperatorToken::compileRegex();

OperatorToken::OperatorToken(OperatorType type, std::wstring::const_iterator pos)
	: Token(TokenType::Operator, static_cast<int>(type), pos) {

}

std::wstring OperatorToken::str() const {
	return operatorTypeStringMap[static_cast<OperatorType>(valueType)];
}

std::unique_ptr<Token> OperatorToken::getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, Token* previousToken) {
	std::wsmatch match;
	if (std::regex_search(start, end, match, s_regex)) {
		if (start != match.prefix().second) {
			return nullptr;
		}
		auto ptr = std::make_unique<OperatorToken>(operatorTypeStringMap[match[0]], start);
		start = match.suffix().first;
		return ptr;
	}
	return nullptr;
}

std::wregex OperatorToken::compileRegex() {
	return generateRegex(s_operatorList, 1);
}
