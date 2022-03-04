#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/MiddlePhoneNumSearch.cpp"

using TestMiddlePhoneNumSearch = TestSearch;

TEST_F(TestMiddlePhoneNumSearch, TestSearchOneItem) {
	auto searcher = make_unique<MiddlePhoneNumSearch>();
	Inform inform = { "phoneNum_middle", "4321" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("010-4321-5678", (*result)[0].phone_num);
}

TEST_F(TestMiddlePhoneNumSearch, TestSearchManyItem) {
	auto searcher = make_unique<MiddlePhoneNumSearch>();
	Inform inform = { "phoneNum_middle", "1234" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(2, result->size());
	EXPECT_EQ("010-1234-5678", (*result)[0].phone_num);
	EXPECT_EQ("010-1234-6789", (*result)[1].phone_num);
}

TEST_F(TestMiddlePhoneNumSearch, TestWrongName) {
	auto searcher = make_unique<MiddlePhoneNumSearch>();
	Inform inform = { "phoneNum_middle", "010-8413-5678" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}

TEST_F(TestMiddlePhoneNumSearch, TestWrongColumn) {
	auto searcher = make_unique<MiddlePhoneNumSearch>();
	Inform inform = { "cl", "2015123099" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}