#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/PhoneNumSearch.cpp"

using TestPhoneNumSearch = TestSearch;

TEST_F(TestPhoneNumSearch, TestSearchOneItem) {
	auto searcher = make_unique<PhoneNumSearch>();
	Inform inform = { "phoneNum", "010-1234-5678" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("010-1234-5678", (*result)[0].phone_num);
}

TEST_F(TestPhoneNumSearch, TestWrongName) {
	auto searcher = make_unique<PhoneNumSearch>();
	Inform inform = { "phoneNum", "010-8413-5678" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}

TEST_F(TestPhoneNumSearch, TestWrongColumn) {
	auto searcher = make_unique<PhoneNumSearch>();
	Inform inform = { "cl","2015123099" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}