#include <iostream>
#include <type_traits>

#include "Error.hpp"
#include "Parser.hpp"

#pragma comment(linker, "/stack:200000000")

int main() {
	Error::logFile = L"programError.txt";

	Parser parser;
	parser.parseFile("program.txt");
}