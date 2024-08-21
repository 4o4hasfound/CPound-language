#pragma once
#include <memory>

#include "Tokens/TokenBase.hpp"

#include "Utils/toString.hpp"
#include "Utils/generateRegex.hpp"

#include "Container/BiUnorderedMap.hpp"

#include "Types.hpp"

class OperatorToken : public Token {
public:
	OperatorToken(OperatorType type, std::wstring::const_iterator pos, const std::wstring& string);

	virtual std::wstring str() const override;

	static std::unique_ptr<Token> getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, const std::wstring& string, Token* previousToken);
private:
	static std::wregex s_regex;
	static std::vector<std::wstring> s_operatorList;

	static std::wregex compileRegex();
};