#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Employee.h"

using namespace std;

enum class Command {
	ADD,
	DEL,
	SCH,
	MOD
};

enum class Option {
	NONE,
	PRINT,
	FIRST_NAME,
	LAST_NAME_AND_PHONE_NUM,
	MIDDLE_PHONE_NUM_AND_MONTH,
	YEAR,
	DAY,
};

struct ParsedLine {
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
};