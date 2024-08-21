#include "Error.hpp"

std::wstring Error::logFile = L"";
int Error::outputLineWidth = 50;

void Error::Log(const std::wstring& errorMessage) {
	std::wcerr << "\n" << errorMessage << "\n";
	LogToFile(errorMessage);
	exit(1);
}
void Error::Log(const PositionInfo& info, const std::wstring& errorMessage, const std::wstring& string) {
	std::wstringstream output;
	output << "\nError at line " << info.lineIndex <<":"<<info.tokenIndexInLine<<" -> ";
	output << errorMessage << "\n";
	output << getOutputLine(info.position, info.lineStartItr, info.lineEndItr) << "\n";

	std::wstring message = output.str();
	std::wcerr << message;
	LogToFile(message);
	exit(1);
}
void Error::Log(Token* token, const std::wstring& errorMessage, const std::wstring& string){
	Error::Log(token->position, errorMessage, string);
}
void Error::LogToFile(const std::wstring& errorMessage) {
	if (logFile.empty()) {
		return;
	}
	std::wofstream file;
	file.open(logFile);

	if (file.fail()) {
		std::wcerr << L"Failed to open target logFile: " << logFile;
		return;
	}
	file<<errorMessage<<L"\n";
}

std::wstring Error::getOutputLine(std::wstring::const_iterator itr, std::wstring::const_iterator start, std::wstring::const_iterator end) {
	int outputLineHalf = outputLineWidth >> 1;
	if (std::distance(start, itr) > outputLineHalf) {
		start = itr - outputLineHalf;
	}
	if (std::distance(itr, end) > outputLineWidth - outputLineHalf) {
		end = itr + (outputLineWidth - outputLineHalf);
	}
	std::wstringstream output;
	output << L"..." << std::wstring(start, end) << "\n   ";

	for (int i = 0; i < std::distance(start, itr); ++i) {
		output << ' ';
	}
	output << '^';
	return output.str();
}
