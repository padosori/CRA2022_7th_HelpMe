#pragma once

#include "Parser.h"

using namespace std;

class Client {
public:
	void readInputFile(const string file_name);
	void parseInputFile(void);
	void runAndWriteOutputFile(const string file_name);

private:
	const int MAX_PRINT_LINES = 5;
	vector<string> raw_lines;
	unique_ptr<vector<ParsedLine>> parsed_lines;
};