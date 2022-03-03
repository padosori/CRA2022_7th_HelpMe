#include "pch.h"
#include "../EmployeeManager/Client.cpp"
#include <iostream>

using namespace std;

TEST(TestClient, readInputFileSuccess) {
	Client client;
	EXPECT_NO_THROW(client.readInputFile("input_20_20.txt"));
}

TEST(TestClient, readInputFileFail) {
	Client client;
	EXPECT_THROW(client.readInputFile("invalid file name.txt"), std::invalid_argument);
}