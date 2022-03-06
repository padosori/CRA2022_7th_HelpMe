#pragma once
#include <string>
using namespace std;

struct Inform {
	string column;
	string value;
};

struct Employee {
	string employee_num;
	string name;
	string first_name;
	string last_name;

	string phone_num;
	string mid_phone_num;
	string last_phone_num;

	string birthday;
	string birthday_year;
	string birthday_month;
	string birthday_day;

	string cl;
	string certi;
};

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