#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Employee.h"

using namespace std;

struct ParsedLine {
	string command_str;
	Command command;
	vector<Option> options;
	vector<Inform> informs;
};

class Parser {
public:
	unique_ptr<vector<ParsedLine>> parse(const vector<string>& str);

private:
	Command getCommand(string str);
	Option getOption(string str);
	ParsedLine parseLine(string str_line);
	void addMoreInform(ParsedLine& parsed_line);
	void transformParsedLine(ParsedLine& parsed_line);
	void transformParsedLineCommand(ParsedLine& parsed_line);
	void transformParsedLineOption(ParsedLine& parsed_line);
};