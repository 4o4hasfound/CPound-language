#include "Tokens/NumericLiteralToken.hpp"

std::vector<std::pair<std::wregex, NumericLiteralType>> NumericLiteralToken::regexTokenList{ {
	{generateRegex({LR"(([-+]?[0-9]+\.[0-9]*))"}, 0, L"a-zA-Z"), NumericLiteralType::Float},
	{generateRegex({LR"(([-+]?[0-9]+))"}, 0, L"a-zA-Z"), NumericLiteralType::Integer}
} };

NumericLiteralToken::NumericLiteralToken(NumericLiteralType literalType, double value, std::wstring::const_iterator pos)
	: Token(TokenType::NumericLiteral, static_cast<int>(literalType), pos)
	, literalValue(value) {

}

std::wstring NumericLiteralToken::str() const {
	switch (static_cast<NumericLiteralType>(valueType)) {
	case NumericLiteralType::Integer:
		return std::to_wstring(static_cast<std::int64_t>(literalValue));
	case NumericLiteralType::Float:
		return std::to_wstring(static_cast<double>(literalValue));
	}
	return L"";
}

std::unique_ptr<Token> NumericLiteralToken::getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, Token* previousToken) {
	std::wsmatch match;
	for (const auto& [regex, tokenType] : regexTokenList) {
		if (std::regex_search(start, end, match, regex)) {
			if (start != match.prefix().second) {
				return nullptr;
			}
			if (match[0].str()[0] == L'-' || match[0].str()[0] == L'+') {
				if (previousToken->isType(Token::Identifier)
					|| previousToken->isType(DelimiterType::RParen)
					|| previousToken->isType(Token::NumericLiteral)
					|| previousToken->isType(Token::StringLiteral)) {
					return nullptr;
				}
			}
			auto ptr = std::make_unique<NumericLiteralToken>(tokenType, std::stod(match[0]), start);
			start = match.suffix().first;
			return ptr;
		}
	}
	return nullptr;
}

std::vector<std::pair<std::wregex, NumericLiteralType>> NumericLiteralToken::compileRegex() {

	return std::vector<std::pair<std::wregex, NumericLiteralType>>{ {
		{generateRegex({ LR"(([-+]?[0-9]+\.[0-9]*))" }, 0, L"a-zA-Z"), NumericLiteralType::Float},
		{ generateRegex({LR"(([-+]?[0-9]+))"}, 0, L"a-zA-Z"), NumericLiteralType::Integer }
		} };
}
