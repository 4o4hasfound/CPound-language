#pragma once

#include <sstream>
#include <fstream>
#include <iostream>

#include "Tokens/TokenBase.hpp"

#include "PositionInfo.hpp"

class Error {
public:
	[[ noreturn ]] static void Log(const std::wstring& errorMessage);
	[[ noreturn ]] static void Log(const PositionInfo& info, const std::wstring& errorMessage, const std::wstring& string);
	[[ noreturn ]] static void Log(Token* token, const std::wstring& errorMessage, const std::wstring& string);
	
	static std::wstring logFile;
	static int outputLineWidth;

private:
	Error() = delete;

	static void LogToFile(const std::wstring& errorMessage);
	static std::wstring getOutputLine(std::wstring::const_iterator itr, std::wstring::const_iterator start, std::wstring::const_iterator end);
};