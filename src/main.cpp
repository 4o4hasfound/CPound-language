#include <iostream>
#include <type_traits>

#include "Error.hpp"
#include "Parser.hpp"

// 100mb of stack
#pragma comment(linker, "/stack:104857600")

int main(int argc, char* argv[]) {
	if (argc == 1 || argc > 3) {
		Error::Log(L"Usage: cpound [input file] ([log file])");
	}

	if (argc == 3) {
		std::wstringstream errorFilename;
		errorFilename << argv[2];
		Error::logFile = errorFilename.str();
	}

	std::wstringstream filename;
	filename << argv[1];

	Parser parser;
	parser.parseFile(filename.str());
}