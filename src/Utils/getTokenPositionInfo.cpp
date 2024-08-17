#include "Utils/getTokenPositionInfo.hpp"

std::wstring::const_iterator getNearestNewline(std::wstring::const_iterator itr, const std::wstring& str) {
	while (itr != str.cbegin() && *itr != L'\n') {
		--itr;
	}
	if (itr == str.cbegin() && *itr != L'\n') {
		return str.cend();
	}
	return itr;
}
PositionInfo getTokenPositionInfo(std::wstring::const_iterator position, const std::wstring& str) {
	int lineIndex = 0;
	std::wstring::const_iterator itr = str.cbegin(), i = str.cbegin();
	for (; i != str.cend() && i < position; itr = i, i = std::find(itr + 1, str.cend(), L'\n')) {
		++lineIndex;
	}
	if (itr != str.cbegin()) {
		++itr;
		--lineIndex;
	}
	return { lineIndex, static_cast<int>(std::distance(itr, position)), itr, i};
}

