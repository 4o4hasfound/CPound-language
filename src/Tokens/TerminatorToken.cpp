#include "Tokens/TerminatorToken.hpp"

std::vector<std::pair<std::wregex, TerminatorType>> TerminatorToken::regexTokenList = compileRegex();

TerminatorToken::TerminatorToken(TerminatorType terminatorType, int terminatorCount, std::wstring::const_iterator pos, const std::wstring& string)
	: Token(Token::Terminator, static_cast<int>(terminatorType), pos, string)
	, count(terminatorCount) {

}

std::wstring TerminatorToken::str() const {
	std::wstringstream ret;
	switch (static_cast<TerminatorType>(valueType)) {
	case TerminatorType::ExclamationMark:
		for (int i = 0; i < count; ++i) {
			ret << L'!';
		}
		return ret.str();
	case TerminatorType::QuestionMark:
		for (int i = 0; i < count; ++i) {
			ret << L'?';
		}
		return ret.str();
	}
	return L"";
}

std::unique_ptr<Token> TerminatorToken::getToken(std::wstring::const_iterator& start, std::wstring::const_iterator& end, const std::wstring& string, Token* previousToken) {
	std::wsmatch match;
	for (const auto& [regex, tokenType]: regexTokenList) {
		if (std::regex_search(start, end, match, regex)) {
			if (start != match.prefix().second) {
				return nullptr;
			}
			auto ptr = std::make_unique<TerminatorToken>(tokenType, match[0].length(), start, string);
			start = match.suffix().first;
			return ptr;
		}
	}
	return nullptr;
}

std::vector<std::pair<std::wregex, TerminatorType>> TerminatorToken::compileRegex() {
	return std::vector<std::pair<std::wregex, TerminatorType>>{ {
		{generateRegex({ LR"((\!+))" }, 0), TerminatorType::ExclamationMark},
		{ generateRegex({LR"((\?+))"}, 0), TerminatorType::QuestionMark }
		} };
}
