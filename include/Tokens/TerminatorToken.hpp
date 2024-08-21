#pragma once
#include <memory>
#include <string>

#include "Types.hpp"

#include "Tokens/TokenBase.hpp"

#include "Utils/generateRegex.hpp"
#include "Utils/toString.hpp"


class TerminatorToken : public Token {
public:
	TerminatorToken(TerminatorType terminatorType, int terminatorCount, std::wstring::const_iterator pos, const std::wstring& string);

	int count;

	virtual std::wstring str() const override;

	static std::unique_ptr<Token> getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, const std::wstring& string, Token* previousToken);
private:
	static std::vector<std::pair<std::wregex, TerminatorType>> regexTokenList;
	static std::vector<std::pair<std::wregex, TerminatorType>> compileRegex();
};