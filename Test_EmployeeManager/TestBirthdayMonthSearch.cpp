#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/BirthdayMonthSearch.cpp"

TEST_F(TestSearch, TestBirthdayMonthSearchInvalid) {
	auto searcher = make_unique<BirthdayMonthSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_month", "13" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestSearch, TestBirthdayMonthSearchNotExist) {
	auto searcher = make_unique<BirthdayMonthSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_month", "07" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestSearch, TestBirthdayMonthSearchExist) {
	auto searcher = make_unique<BirthdayMonthSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday_month", "02" });
	EXPECT_EQ(2, results->size());
}
