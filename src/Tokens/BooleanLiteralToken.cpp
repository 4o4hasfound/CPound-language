#include "Tokens/BooleanLiteralToken.hpp"

std::vector<std::pair<std::wregex, BooleanType>> BooleanLiteralToken::regexTokenList = compileRegex();

BooleanLiteralToken::BooleanLiteralToken(BooleanType booleanType, std::wstring::const_iterator pos, const std::wstring& string)
	: Token(TokenType::Boolean, static_cast<int>(booleanType), pos, string) {

}

std::wstring BooleanLiteralToken::str() const {
	return booleanTypeStringMap[static_cast<BooleanType>(valueType)];
}

std::unique_ptr<Token> BooleanLiteralToken::getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, const std::wstring& string, Token* previousToken) {
	std::wsmatch match;
	for (const auto& regexToken : regexTokenList) {
		if (std::regex_search(start, end, match, regexToken.first)) {
			if (start != match.prefix().second) {
				return nullptr;
			}
			auto ptr = std::make_unique<BooleanLiteralToken>(regexToken.second, start, string);
			start = match.suffix().first;
			return ptr;
		}
	}
	return nullptr;
}

std::vector<std::pair<std::wregex, BooleanType>> BooleanLiteralToken::compileRegex() {
	return std::vector<std::pair<std::wregex, BooleanType>>{ {
		{generateRegex({ LR"(true)" }, 0, L"a-zA-Z"), BooleanType::True},
		{ generateRegex({LR"(maybe)"}, 0, L"a-zA-Z"), BooleanType::Maybe },
		{ generateRegex({LR"(false)"}, 0, L"a-zA-Z"), BooleanType::False },
		} };;
}
