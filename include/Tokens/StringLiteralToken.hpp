#pragma once
#include <vector>
#include <memory>
#include <string>

#include "Types.hpp"

#include "Tokens/TokenBase.hpp"

#include "Utils/generateRegex.hpp"
#include "Utils/toString.hpp"

#include "Container/BiUnorderedMap.hpp"


class StringLiteralToken : public Token {
public:
	StringLiteralToken(const std::wstring& value, std::wstring::const_iterator pos);

	std::wstring literalValue;

	virtual std::wstring str() const override;

	static std::unique_ptr<Token> getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, Token* previousToken);
private:
	static std::wregex s_regex;
	static std::wregex compileRegex();
};
