#include "pch.h"
#include "../EmployeeManager/Parser.h"
#include "../EmployeeManager/Parser.cpp"

TEST(TestParser, TestParseADD) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::ADD);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "15123099");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[1].value.c_str(), "VXIHXOTH JHOP");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[2].value.c_str(), "CL3");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[3].value.c_str(), "010-3112-2609");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[4].value.c_str(), "19771211");
 	EXPECT_STREQ(parsed_file_vector->at(0).informs[5].value.c_str(), "ADV");
}

TEST(TestParser, TestParseSCH) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("SCH,-p,-d, ,birthday,04");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);

	EXPECT_EQ(parsed_file_vector->at(0).command, Command::SCH);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::PRINT);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::DAY);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "birthday");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "04");
}

TEST(TestParser, TestParseMOD) {
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

TEST(TestParser, TestParseDEL) {
	Parser parser;
	vector<string> str_vector;

	str_vector.emplace_back("DEL, , , ,employeeNum,18115040");

	unique_ptr<vector<ParsedLine>> parsed_file_vector = parser.parse(str_vector);
	EXPECT_EQ(parsed_file_vector->at(0).command, Command::DEL);
	EXPECT_EQ(parsed_file_vector->at(0).options[0], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[1], Option::NONE);
	EXPECT_EQ(parsed_file_vector->at(0).options[2], Option::NONE);
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].column.c_str(), "employeeNum");
	EXPECT_STREQ(parsed_file_vector->at(0).informs[0].value.c_str(), "18115040");
}