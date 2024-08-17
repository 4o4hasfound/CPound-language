#pragma once
#include <memory>
#include <string>

#include "Types.hpp"

#include "Tokens/TokenBase.hpp"

#include "Utils/generateRegex.hpp"
#include "Utils/toString.hpp"

class IdentifierToken : public Token {
public:
	IdentifierToken(const std::wstring& string, std::wstring::const_iterator pos);

	std::wstring identifierName;

	virtual std::wstring str() const override;

	static std::unique_ptr<Token> getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, Token* previousToken);
private:
	static std::wregex s_regex;

	static std::wregex compileRegex();
};
