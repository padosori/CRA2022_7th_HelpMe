#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/FirstNameSearch.cpp"

using TestFirstNameSearch = TestSearch;

TEST_F(TestFirstNameSearch, TestSearchOneItem) {
	auto searcher = make_unique<FirstNameSearch>();
	Inform inform = { "name_first", "Gildong" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("Gildong Hong", (*result)[0].name);
}

TEST_F(TestFirstNameSearch, TestSearchManyItem) {
	auto searcher = make_unique<FirstNameSearch>();
	Inform inform = { "name_first", "Gyoungrae" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(2, result->size());
	EXPECT_EQ("1999112233", (*result)[0].employee_num);
	EXPECT_EQ("2001001122", (*result)[1].employee_num);
}

TEST_F(TestFirstNameSearch, TestWrongName) {
	auto searcher = make_unique<FirstNameSearch>();
	Inform inform = { "name_first", "ENDMA" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}

TEST_F(TestFirstNameSearch, TestWrongColumn) {
	auto searcher = make_unique<FirstNameSearch>();
	Inform inform = { "cl", "2015123099" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}