#pragma once

#include "Parser.h"

using namespace std;

class Client {
public:
	void readInputFile(const string file_name);
	void parseInputFile(void);

private:
	vector<string> file_str_;
	unique_ptr<vector<ParsedLine>> parsed_file_;
};