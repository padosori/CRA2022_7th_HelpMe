#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/BirthdaySearch.cpp"

TEST_F(TestSearch, TestBirthdaySearchInvalid) {
	auto searcher = make_unique<BirthdaySearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday", "20000000" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestSearch, TestBirthdaySearchNotExist) {
	auto searcher = make_unique<BirthdaySearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday", "20000101" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestSearch, TestBirthdaySearchExist) {
	auto searcher = make_unique<BirthdaySearch>();
	auto results = searcher->search(*employeeMap, Inform{ "birthday", "20010103" });
	EXPECT_EQ(1, results->size());
}
