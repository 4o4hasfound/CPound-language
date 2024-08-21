#include "PositionInfo.hpp"

PositionInfo::PositionInfo(std::wstring::const_iterator _position, const std::wstring& str)
	: position(_position) {
	lineIndex = 0;
	std::wstring::const_iterator itr = str.cbegin(), i = str.cbegin();
	for (; i != str.cend() && i < position; itr = i, i = std::find(itr + 1, str.cend(), L'\n')) {
		++lineIndex;
	}
	if (itr != str.cbegin()) {
		++itr;
		--lineIndex;
	}
	tokenIndexInLine = static_cast<int>(std::distance(itr, position));
	lineStartItr = itr;
	lineEndItr = i;
}
