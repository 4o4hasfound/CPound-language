#include "Tokens/LifetimeToken.hpp"

std::vector<std::pair<std::wregex, LifetimeType>> LifetimeToken::regexTokenList = compileRegex();

LifetimeToken::LifetimeToken(LifetimeType lifetimeType, double value, std::wstring::const_iterator pos)
	: Token(Token::Lifetime, static_cast<int>(lifetimeType), pos)
	, lifetimeValue(value) {
}

std::wstring LifetimeToken::str() const {
	std::wstringstream ret;
	switch (static_cast<LifetimeType>(valueType)) {
	case LifetimeType::Line:
		ret << L'<' << static_cast<int>(lifetimeValue) << L'>';
		break;
	case LifetimeType::Second:
		ret << L'<' << lifetimeValue << L"s>";
		break;
	case LifetimeType::Scope:
		ret << L'<' << static_cast<int>(lifetimeValue) << L"sc>";
		break;
	}
	return ret.str();
}

std::unique_ptr<Token> LifetimeToken::getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, Token* previousToken) {
	std::wsmatch match;
	for (const auto& [regex, tokenType] : regexTokenList) {
		if (std::regex_search(start, end, match, regex)) {
			if (start != match.prefix().second) {
				return nullptr;
			}
			auto ptr = std::make_unique<LifetimeToken>(tokenType, std::stod(match[2]), start);
			start = match.suffix().first;
			return ptr;
		}
	}
	return nullptr;
}

std::vector<std::pair<std::wregex, LifetimeType>> LifetimeToken::compileRegex() {
	return std::vector<std::pair<std::wregex, LifetimeType>>{ {
		{ generateRegex({ LR"(< *([-+]?[0-9]+) *>)" }, 0, L""), LifetimeType::Line },
		{ generateRegex({LR"(< *([-+]?[0-9]+(\.[0-9]*)?) *s *>)"}, 0, L""), LifetimeType::Second },
		{ generateRegex({LR"(< *([+]?[0-9]+) *sc *>)"}, 0, L""), LifetimeType::Scope }
		} };
}
