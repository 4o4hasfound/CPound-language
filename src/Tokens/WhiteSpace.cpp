#include "Tokens/WhiteSpace.hpp"

std::wregex WhiteSpace::s_regex = generateRegex({ LR"(((//[^\n]*)?[\s:]*)*)" }, 0);
std::wregex WhiteSpace::s_newline{ L"\n", std::regex_constants::optimize };

bool WhiteSpace::eat(std::wstring::const_iterator& start, std::wstring::const_iterator& end) {
	std::wsmatch match;
	if (std::regex_search(start, end, match, s_regex)) {
		if (start != match.prefix().second) {
			return false;
		}
		start = match.suffix().first;
		return true;
	}
	return false;
}