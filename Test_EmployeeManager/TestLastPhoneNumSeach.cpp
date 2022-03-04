#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/LastPhoneNumSearch.cpp"

using TestLastPhoneNumSearch = TestSearch;

TEST_F(TestLastPhoneNumSearch, TestSearchOneItem) {
	auto searcher = make_unique<LastPhoneNumSearch>();
	Inform inform = { "phoneNum_last", "6789" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("010-1234-6789", (*result)[0].phone_num);
}

TEST_F(TestLastPhoneNumSearch, TestSearchManyItem) {
	auto searcher = make_unique<LastPhoneNumSearch>();
	Inform inform = { "phoneNum_last", "5678" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(2, result->size());
	EXPECT_EQ("010-1234-5678", (*result)[0].phone_num);
	EXPECT_EQ("010-4321-5678", (*result)[1].phone_num);
}

TEST_F(TestLastPhoneNumSearch, TestWrongName) {
	auto searcher = make_unique<LastPhoneNumSearch>();
	Inform inform = { "phoneNum_last", "010-8413-5678" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}

TEST_F(TestLastPhoneNumSearch, TestWrongColumn) {
	auto searcher = make_unique<LastPhoneNumSearch>();
	Inform inform = { "cl", "2015123099" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}