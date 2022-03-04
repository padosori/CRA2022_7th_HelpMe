#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/BirthdayDaySearch.cpp"

TEST_F(TestSearch, TestBirthdayDaySearchInvalid) {
	auto searcher = make_unique<BirthdayDaySearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_day", "32" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestSearch, TestBirthdayDaySearchNotExist) {
	auto searcher = make_unique<BirthdayDaySearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_day", "07" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestSearch, TestBirthdayDaySearchExist) {
	auto searcher = make_unique<BirthdayDaySearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_day", "03" });
	EXPECT_EQ(3, results->size());
}
