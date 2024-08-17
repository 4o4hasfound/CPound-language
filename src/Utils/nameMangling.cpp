#include "Utils/nameMangling.hpp"

std::wstring mangleName(const std::wstring& symbol, const std::vector<std::shared_ptr<Value>>& params) {
	std::wstringstream wss;
	wss << symbol << "@";
	for (const auto& variable : params) {
		wss << variable->type << L'_';
	}
	return wss.str();
}
