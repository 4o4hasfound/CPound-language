#pragma once
#include <string>

#include "Types.hpp"

class Token {
public:
	enum TokenType {
		NumericLiteral,
		StringLiteral,
		Boolean,
		Operator,
		Delimiter,
		Terminator,
		Identifier,
		Keyword,
		Lifetime
	};

	TokenType type;
	int valueType;

	std::wstring::const_iterator position;

	Token(TokenType tokenType, std::wstring::const_iterator pos);
	Token(TokenType tokenType, int underLyingValueType, std::wstring::const_iterator pos);

	bool isType(TokenType targetTokenType) const;

	template<typename T, typename = std::enable_if_t<std::is_enum_v<T>>>
	bool isType(T targetValueType) const;

	virtual std::wstring str() const = 0;
};

template<typename T, typename>
inline bool Token::isType(T targetValueType) const {
	if (static_cast<int>(targetValueType) != valueType) {
		return false;
	}
	if (std::is_same_v<T, OperatorType>) {
		return type == Operator;
	}
	else if (std::is_same_v<T, BooleanType>) {
		return type == Boolean;
	}
	else if (std::is_same_v<T, KeywordType>) {
		return type == Keyword;
	}
	else if (std::is_same_v<T, DelimiterType>) {
		return type == Delimiter;
	}
	else if (std::is_same_v<T, LifetimeType>) {
		return type == Lifetime;
	}
	else if (std::is_same_v<T, NumericLiteralType>) {
		return type == NumericLiteral;
	}
	else if (std::is_same_v<T, TerminatorType>) {
		return type == Terminator;
	}
}
