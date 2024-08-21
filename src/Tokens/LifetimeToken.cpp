#include "Tokens/LifetimeToken.hpp"

std::vector<std::pair<std::wregex, LifetimeType>> LifetimeToken::regexTokenList = compileRegex();

LifetimeToken::LifetimeToken(LifetimeType lifetimeType, double value, std::wstring::const_iterator pos, const std::wstring& string)
	: Token(Token::Lifetime, static_cast<int>(lifetimeType), pos, string)
	, lifetimeValue(value) {
}

std::wstring LifetimeToken::str() const {
	std::wstringstream ret;
	switch (static_cast<LifetimeType>(valueType)) {
	case LifetimeType::ForwardLine:
		ret << L'<' << static_cast<int>(lifetimeValue) << L'f>';
		break;
	case LifetimeType::BackwardLine:
		ret << L'<' << static_cast<int>(lifetimeValue) << L'b>';
		break;
	case LifetimeType::Time:
		ret << L'<' << lifetimeValue << L"s>";
		break;
	case LifetimeType::Scope:
		ret << L'<' << static_cast<int>(lifetimeValue) << L"sc>";
		break;
	}
	return ret.str();
}

std::unique_ptr<Token> LifetimeToken::getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, const std::wstring& string, Token* previousToken) {
	std::wsmatch match;
	for (const auto& [regex, tokenType] : regexTokenList) {
		if (std::regex_search(start, end, match, regex)) {
			if (start != match.prefix().second) {
				return nullptr;
			}
			auto ptr = std::make_unique<LifetimeToken>(tokenType, std::stod(match[2]), start, string);
			start = match.suffix().first;
			return ptr;
		}
	}
	return nullptr;
}

std::vector<std::pair<std::wregex, LifetimeType>> LifetimeToken::compileRegex() {
	return std::vector<std::pair<std::wregex, LifetimeType>>{ {
		{ generateRegex({ LR"(< *([-+]?[0-9]+(\.[0-9]*)?) *f *>)" }, 0, L""), LifetimeType::ForwardLine },
		{ generateRegex({ LR"(< *([-+]?[0-9]+(\.[0-9]*)?) *b *>)" }, 0, L""), LifetimeType::BackwardLine },
		{ generateRegex({ LR"(< *([-+]?[0-9]+(\.[0-9]*)?) *s *>)"}, 0, L""), LifetimeType::Time },
		{ generateRegex({ LR"(< *([-+]?[0-9]+(\.[0-9]*)?) *sc *>)"}, 0, L""), LifetimeType::Scope }
		} };
}
