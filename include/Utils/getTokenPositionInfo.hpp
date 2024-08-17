#pragma once
#include <string>

#include "Tokens/TokenBase.hpp"

struct PositionInfo {
	int lineIndex;
	int tokenIndexInLine;
	std::wstring::const_iterator lineStartItr;
	std::wstring::const_iterator lineEndItr;
};

PositionInfo getTokenPositionInfo(std::wstring::const_iterator position, const std::wstring& str);

