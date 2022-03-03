#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/Search.h"
#include "../EmployeeManager/ClSearch.cpp"

TEST_F(TestSearch, TestClSearchInvalid) {
	auto searcher = make_unique<ClSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "cl", "CL0" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestSearch, TestClSearchNotExist) {
	auto searcher = make_unique<ClSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "cl", "CL4" });
	EXPECT_EQ(0, results->size());
}

TEST_F(TestSearch, TestClSearchExist) {
	auto searcher = make_unique<ClSearch>();
	auto results = searcher->search(*employeeMap, Inform{ "cl", "CL1" });
	EXPECT_EQ(2, results->size());
}
