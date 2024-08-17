#include "Utils/generateRegex.hpp"

std::wregex generateRegex(const std::vector<std::wstring>& strings, bool replaceSpecialCharacter, const std::wstring& cannotEndsWith, std::regex_constants::syntax_option_type flags) {
	std::wregex ret;
	std::wstringstream wss;
	std::wregex specialCharacters(LR"([\.\^\$\*\+\?\(\)\[\]\{\}\\\|\/])");

	wss << L"^(";
	for (int i = 0; i < strings.size(); ++i) {
		if (replaceSpecialCharacter) {
			wss << std::regex_replace(strings[i], specialCharacters, LR"(\$&)");
		}
		else {
			wss << strings[i];
		}
		if (i != strings.size() - 1) {
			wss << '|';
		}
	}
	wss << L')';
	if (!cannotEndsWith.empty()) {
		wss << LR"((?![)" + cannotEndsWith + LR"(]))";
	}
	ret.assign(wss.str(), std::regex_constants::optimize | std::regex_constants::icase | flags);
	return ret;
}
