#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/BirthdayYearSearch.cpp"

using TestBirthdayYearSearch = TestSearch;

TEST_F(TestBirthdayYearSearch, TestBirthdayYearSearchInvalid) {
	auto searcher = make_unique<BirthdayYearSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_year", "20000000" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestBirthdayYearSearch, TestBirthdayYearSearchNotExist) {
	auto searcher = make_unique<BirthdayYearSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_year", "1998" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestBirthdayYearSearch, TestBirthdayYearSearchExist) {
	auto searcher = make_unique<BirthdayYearSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_year", "2000" });
	EXPECT_EQ(2, results->size());
	EXPECT_EQ("2000112233", (*results)[0].employee_num);
	EXPECT_EQ("2001001122", (*results)[1].employee_num);
}
