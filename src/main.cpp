#include <iostream>
#include <type_traits>

#include "Error.hpp"
#include "Parser.hpp"

// 100mb of stack
#pragma comment(linker, "/stack:104857600")

int main(int argc, char* argv[]) {
	if (argc == 1 || argc > 4) {
		Error::Log(L"Usage: cpound [input file] ([log file]) (--debug)");
	}

	bool debug = false;

	if (argc == 3) {
		if (strcmp(argv[2], "--debug")) {
			debug = true;
		}
		else {
			std::wstringstream errorFilename;
			errorFilename << argv[2];
			Error::logFile = errorFilename.str();
		}
	}
	else {
		if (!strcmp(argv[3], "--debug")) {
			Error::Log(L"Usage: cpound [input file] ([log file]) (--debug)");
		}
		debug = true;
		std::wstringstream errorFilename;
		errorFilename << argv[2];
		Error::logFile = errorFilename.str();
	}

	std::wstringstream filename;
	filename << argv[1];

	Parser parser;
	parser.parseFile(filename.str());

	if (debug) {
		parser.debugAST();
	}
	std::wcout << "\n";
	
	parser.run();
}