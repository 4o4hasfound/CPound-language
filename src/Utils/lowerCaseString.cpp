#include "Utils/lowerCaseString.hpp"

bool ichar_equals(wchar_t a, wchar_t b) {
    return std::towlower(a) == std::towlower(b);
}

bool lowerCaseCompare::operator()(const std::wstring& a, const std::wstring& b) const {
	return a.size() == b.size() && std::equal(a.begin(), a.end(), b.begin(), ichar_equals);
}