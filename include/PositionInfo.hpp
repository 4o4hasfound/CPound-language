#pragma once
#include <string>

struct PositionInfo {
	PositionInfo() = default;
	PositionInfo(std::wstring::const_iterator _position, const std::wstring& str);
	int lineIndex;
	int tokenIndexInLine;
	std::wstring::const_iterator position;
	std::wstring::const_iterator lineStartItr;
	std::wstring::const_iterator lineEndItr;
};