#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/BirthdayDaySearch.cpp"

using TestBirthdayDaySearch = TestSearch;

TEST_F(TestBirthdayDaySearch, TestBirthdayDaySearchInvalid) {
	auto searcher = make_unique<BirthdayDaySearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_day", "32" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestBirthdayDaySearch, TestBirthdayDaySearchNotExist) {
	auto searcher = make_unique<BirthdayDaySearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_day", "07" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestBirthdayDaySearch, TestBirthdayDaySearchExist) {
	auto searcher = make_unique<BirthdayDaySearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_day", "03" });
	EXPECT_EQ(3, results->size());
	EXPECT_EQ("1999112233", (*results)[0].employee_num);
	EXPECT_EQ("2001001122", (*results)[1].employee_num);
	EXPECT_EQ("2001112233", (*results)[2].employee_num);
}
