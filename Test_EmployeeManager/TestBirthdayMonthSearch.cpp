#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/BirthdayMonthSearch.cpp"

using TestBirthdayMonthSearch = TestSearch;

TEST_F(TestBirthdayMonthSearch, TestBirthdayMonthSearchInvalid) {
	auto searcher = make_unique<BirthdayMonthSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_month", "13" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestBirthdayMonthSearch, TestBirthdayMonthSearchNotExist) {
	auto searcher = make_unique<BirthdayMonthSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_month", "07" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestBirthdayMonthSearch, TestBirthdayMonthSearchExist) {
	auto searcher = make_unique<BirthdayMonthSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_month", "02" });
	EXPECT_EQ(2, results->size());
	EXPECT_EQ("1999112233", (*results)[0].employee_num);
	EXPECT_EQ("2001001122", (*results)[1].employee_num);
}
