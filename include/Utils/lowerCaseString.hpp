#pragma once
#include <string>
#include <cwctype>
#include <algorithm>

bool ichar_equals(wchar_t a, wchar_t b);

struct lowerCaseCompare {
	bool operator()(const std::wstring& a, const std::wstring& b) const;
};