#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/BirthdayYearSearch.cpp"

TEST_F(TestSearch, TestBirthdayYearSearchInvalid) {
	auto searcher = make_unique<BirthdayYearSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_year", "20000000" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestSearch, TestBirthdayYearSearchNotExist) {
	auto searcher = make_unique<BirthdayYearSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_year", "1998" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestSearch, TestBirthdayYearSearchExist) {
	auto searcher = make_unique<BirthdayYearSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_year", "2000" });
	EXPECT_EQ(2, results->size());
}
