#pragma once
#include <memory>
#include <string>

#include "Types.hpp"

#include "Tokens/TokenBase.hpp"

#include "Utils/generateRegex.hpp"
#include "Utils/toString.hpp"

#include "Container/BiUnorderedMap.hpp"


class KeywordToken : public Token {
public:
	KeywordToken(KeywordType KeywordType, std::wstring::const_iterator pos);

	virtual std::wstring str() const override;

	static std::unique_ptr<Token> getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, Token* previousToken);
private:
	static std::wregex s_regex;

	static std::vector<std::wstring> s_keywordRegexes;
	static std::wregex s_functionRegex;

	static std::wregex compileRegex();
};