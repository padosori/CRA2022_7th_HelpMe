#include "pch.h"
#include "../EmployeeManager/Client.cpp"
#include <iostream>

using namespace std;

TEST(TestClient, TestReadInputFileSuccess) {
	Client client;
	EXPECT_NO_THROW(client.readInputFile("input_20_20.txt"));
}

TEST(TestClient, TestReadInputFileFail) {
	Client client;
	EXPECT_THROW(client.readInputFile("invalid file name.txt"), std::invalid_argument);
}

TEST(TestClient, TestParseInputFile) {
	Client client;
	EXPECT_NO_THROW(client.readInputFile("input_20_20.txt"));
	EXPECT_NO_THROW(client.parseInputFile());
}

TEST(TestClient, TestRun) {
	Client client;

	EXPECT_NO_THROW(client.readInputFile("input_20_20.txt"));
	EXPECT_NO_THROW(client.parseInputFile());
	EXPECT_NO_THROW(client.runAndWriteOutputFile("output_20_20_unit_test_results.txt"));
}