#include "Tokens/WhiteSpace.hpp"

std::wregex WhiteSpace::s_regex = generateRegex({ LR"(((//[^\n]*)?[\s:]*))" }, 0);
std::wregex WhiteSpace::s_newline{ L"\n", std::regex_constants::optimize };

void WhiteSpace::eat(std::wstring::const_iterator& start, std::wstring::const_iterator& end) {
	std::wsmatch match;
	while (std::regex_search(start, end, match, s_regex) && match[0].length()) {
		if (start != match.prefix().second) {
			return;
		}
		start = match.suffix().first;
	}
	return;
}