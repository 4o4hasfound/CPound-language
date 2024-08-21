#pragma once
#include <vector>
#include <memory>
#include <string>

#include "Types.hpp"

#include "Tokens/TokenBase.hpp"

#include "Utils/generateRegex.hpp"
#include "Utils/toString.hpp"

#include "Container/BiUnorderedMap.hpp"


class NumericLiteralToken : public Token {
public:
	NumericLiteralToken(NumericLiteralType literalType, double value, std::wstring::const_iterator pos, const std::wstring& string);

	double literalValue;

	virtual std::wstring str() const override;

	static std::unique_ptr<Token> getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, const std::wstring& string, Token* previousToken);
private:
	static std::vector<std::pair<std::wregex, NumericLiteralType>> regexTokenList;
	static std::vector<std::pair<std::wregex, NumericLiteralType>> compileRegex();
};