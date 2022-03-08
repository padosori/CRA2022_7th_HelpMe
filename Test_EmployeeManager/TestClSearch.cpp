#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/Search.h"
#include "../EmployeeManager/ClSearch.cpp"

using TestClSearch = TestSearch;

TEST_F(TestClSearch, TestClSearchInvalid) {
	auto searcher = make_unique<ClSearch>();
	auto results = searcher->search(employee_management, Inform{ "cl", "CL0" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestClSearch, TestClSearchNotExist) {
	auto searcher = make_unique<ClSearch>();
	auto results = searcher->search(employee_management, Inform{ "cl", "CL4" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestClSearch, TestClSearchExist) {
	auto searcher = make_unique<ClSearch>();
	auto results = searcher->search(employee_management, Inform{ "cl", "CL1" });
	EXPECT_EQ(2, results->size());
	EXPECT_EQ("2000112233", (*results)[0].employee_num);
	EXPECT_EQ("2001001122", (*results)[1].employee_num);
}
