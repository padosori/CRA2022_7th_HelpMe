#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Employee.h"

using namespace std;

struct ParsedLine {
	Command command;
	vector<Option> options;
	vector<Inform> informs;

	string command_str;
	vector<string> options_str;
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
	void transformParsedLineValue(ParsedLine& parsed_line);
	void transformParsedLineOption(ParsedLine& parsed_line);
	void addYearPrefix(string& str);
	string makeStrParsedLine(ParsedLine parsed_line);
};