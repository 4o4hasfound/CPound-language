#include "Tokens/TokenBase.hpp"

Token::Token(TokenType tokenType, int underLyingValueType, std::wstring::const_iterator pos, const std::wstring& string)
	: type(tokenType), valueType(underLyingValueType), position(pos, string) {

}

Token::Token(TokenType tokenType, std::wstring::const_iterator pos, const std::wstring& string)
	: type(tokenType), valueType(-1), position(pos, string) {

}

bool Token::isType(TokenType targetTokenType) const {
	return type == targetTokenType;
}
