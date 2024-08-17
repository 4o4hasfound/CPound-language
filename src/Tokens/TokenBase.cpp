#include "Tokens/TokenBase.hpp"

Token::Token(TokenType tokenType, int underLyingValueType, std::wstring::const_iterator pos)
	: type(tokenType), valueType(underLyingValueType), position(pos) {

}

Token::Token(TokenType tokenType, std::wstring::const_iterator pos)
	: type(tokenType), valueType(-1), position(pos) {

}

bool Token::isType(TokenType targetTokenType) const {
	return type == targetTokenType;
}
