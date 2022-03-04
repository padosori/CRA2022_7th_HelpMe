#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/CertiSearch.cpp"

TEST_F(TestSearch, TestCertiSearchInvalid) {
	auto searcher = make_unique<CertiSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "certi", "ABC" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestSearch, TestCertiSearchNotExist) {
	auto searcher = make_unique<CertiSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "certi", "ADV" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestSearch, TestCertiSearchExist) {
	auto searcher = make_unique<CertiSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "certi", "EX" });
	EXPECT_EQ(2, results->size());
}
