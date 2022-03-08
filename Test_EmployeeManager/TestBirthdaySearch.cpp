#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/BirthdaySearch.cpp"

using TestBirthdaySearch = TestSearch;

TEST_F(TestBirthdaySearch, TestBirthdaySearchInvalid) {
	auto searcher = make_unique<BirthdaySearch>();
	auto results = searcher->search(employee_management, Inform{ "birthday", "20000000" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestBirthdaySearch, TestBirthdaySearchNotExist) {
	auto searcher = make_unique<BirthdaySearch>();
	auto results = searcher->search(employee_management, Inform{ "birthday", "20000101" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestBirthdaySearch, TestBirthdaySearchExist) {
	auto searcher = make_unique<BirthdaySearch>();
	auto results = searcher->search(employee_management, Inform{ "birthday", "20010103" });
	EXPECT_EQ(1, results->size());
	EXPECT_EQ("2001112233", (*results)[0].employee_num);
}
