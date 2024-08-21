#pragma once
#include <memory>
#include <string>

#include "Types.hpp"
#include "Tokens/TokenBase.hpp"

#include "Utils/toString.hpp"
#include "Utils/generateRegex.hpp"


class BooleanLiteralToken : public Token {
public:
	BooleanLiteralToken(BooleanType booleanType, std::wstring::const_iterator pos, const std::wstring& string);

	virtual std::wstring str() const override;

	static std::unique_ptr<Token> getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, const std::wstring& string, Token* previousToken);
private:
	static std::vector<std::pair<std::wregex, BooleanType>> regexTokenList;

	static std::vector<std::pair<std::wregex, BooleanType>> compileRegex();
};