#pragma once
#include <regex>
#include <string>

#include "Utils/generateRegex.hpp"

class WhiteSpace {
public:
	static bool eat(std::wstring::const_iterator& start, std::wstring::const_iterator& end);
private:
	static std::wregex s_regex;
	static std::wregex s_newline;
};