#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/LastNameSearch.cpp"

using TestLastNameSearch = TestSearch;

TEST_F(TestLastNameSearch, TestSearchOneItem) {
	auto searcher = make_unique<LastNameSearch>();
	Inform inform = { "name_last", "Seong" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("Choonhyang Seong", (*result)[0].name);
}

TEST_F(TestLastNameSearch, TestSearchManyItem) {
	auto searcher = make_unique<LastNameSearch>();
	Inform inform = { "name_last", "Hong" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(3, result->size());
	EXPECT_EQ("00112233", (*result)[0].employee_num); 
	EXPECT_EQ("01001122", (*result)[1].employee_num);
	EXPECT_EQ("99112233", (*result)[2].employee_num);
}

TEST_F(TestLastNameSearch, TestWrongName) {
	auto searcher = make_unique<LastNameSearch>();
	Inform inform = { "name_last", "ENDMA" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}

TEST_F(TestLastNameSearch, TestWrongColumn) {
	auto searcher = make_unique<LastNameSearch>();
	Inform inform = { "cl", "2015123099" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}