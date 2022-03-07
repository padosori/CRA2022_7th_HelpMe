#include "pch.h"
#include "../EmployeeManager/Parser.h"
#include "../EmployeeManager/Parser.cpp"

TEST(TestParser, TestParseAdd) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::ADD);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "employeeNum");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "2015123099");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[1].column.c_str(), "name");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[1].value.c_str(), "VXIHXOTH JHOP");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[2].column.c_str(), "cl");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[2].value.c_str(), "CL3");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[3].column.c_str(), "phoneNum");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[3].value.c_str(), "010-3112-2609");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[4].column.c_str(), "birthday");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[4].value.c_str(), "19771211");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[5].column.c_str(), "certi");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[5].value.c_str(), "ADV");
}

TEST(TestParser, TestParseSearch) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("SCH,-p, , ,birthday,20050520");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::SCH);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::PRINT);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "birthday");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "20050520");
}

TEST(TestParser, TestParseModify) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("MOD,-p, , ,name,FB NTAWR,birthday,20050520");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);
	EXPECT_EQ(parsed_file_vector->at(0).command, Command::MOD);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::PRINT);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "name");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "FB NTAWR");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[1].column.c_str(), "birthday");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[1].value.c_str(), "20050520");
}

TEST(TestParser, TestParseDelete) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, , , ,employeeNum,18115040");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);
	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "employeeNum");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "2018115040");
}

TEST(TestParser, TestParseDeleteName) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, , , ,name,KIM KYUMOK");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);
	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "name");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "KIM KYUMOK");
}

TEST(TestParser, TestParseDeleteNameFirst) {
	Parser parser;
	vector<string> str_vector;
	str_vector.emplace_back("DEL, ,-f, ,name,KYUMOK");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::FIRST_NAME);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "name_first");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "KYUMOK");
}

TEST(TestParser, TestParseDeleteNameLast) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, ,-l, ,name,KIM");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::LAST_NAME_AND_PHONE_NUM);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "name_last");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "KIM");
}

TEST(TestParser, TestParseDeletePhoneNum) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, , , ,phoneNum,010-1234-5678");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "phoneNum");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "010-1234-5678");
}

TEST(TestParser, TestParseDeletePhoneNumMiddle) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, ,-m, ,phoneNum,1234");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::MIDDLE_PHONE_NUM_AND_MONTH);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "phoneNum_middle");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "1234");
}

TEST(TestParser, TestParseDeletePhoneNumLast) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, ,-l, ,phoneNum,5678");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::LAST_NAME_AND_PHONE_NUM);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "phoneNum_last");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "5678");
}

TEST(TestParser, TestParseDeleteBirthday) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, , , ,birthday,19900906");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "birthday");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "19900906");
}

TEST(TestParser, TestParseDeleteBirthdayYear) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, ,-y, ,birthday,1990");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::YEAR);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "birthday_year");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "1990");
}

TEST(TestParser, TestParseDeleteBirthdayMonth) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, ,-m, ,birthday,09");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::MIDDLE_PHONE_NUM_AND_MONTH);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "birthday_month");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "09");
}

TEST(TestParser, TestParseDeleteBirthdayDay) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, ,-d, ,birthday,06");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::DAY);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "birthday_day");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "06");
}

TEST(TestParser, TestParseDeleteEmployeeNum) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, , , ,employeeNum,18115040");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "employeeNum");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "2018115040");
}

TEST(TestParser, TestParseDeleteCerti) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, , , ,certi,PRO");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "certi");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "PRO");
}

TEST(TestParser, TestParseDeleteCl) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, , , ,cl,CL4");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "cl");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "CL4");
}