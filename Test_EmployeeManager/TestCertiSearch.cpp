#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/CertiSearch.cpp"

using TestCertiSearch = TestSearch;

TEST_F(TestCertiSearch, TestCertiSearchInvalid) {
	auto searcher = make_unique<CertiSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "certi", "ABC" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestCertiSearch, TestCertiSearchNotExist) {
	auto searcher = make_unique<CertiSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "certi", "ADV" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestCertiSearch, TestCertiSearchExist) {
	auto searcher = make_unique<CertiSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "certi", "EX" });
	EXPECT_EQ(2, results->size());
	EXPECT_EQ("1999112233", (*results)[0].employee_num);
	EXPECT_EQ("2001001122", (*results)[1].employee_num);
}
