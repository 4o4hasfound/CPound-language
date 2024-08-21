#pragma once
#include <memory>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <iostream>

#include "Tokens.hpp"

#include "Error.hpp"

#include "PositionInfo.hpp"

class Lexer {
public:
	Lexer(std::vector<std::unique_ptr<Token>>& tokens);

	void tokenize(const std::wstring& input);
private:
	std::vector<std::unique_ptr<Token>>& m_tokens;
};