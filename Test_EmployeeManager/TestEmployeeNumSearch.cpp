#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/EmployeeNumSearch.cpp"

using TestEmployeeNumSearch = TestSearch;
TEST_F(TestEmployeeNumSearch, TestSearchItem) {
	auto searcher = make_unique<EmployeeNumSearch>();
	Inform inform = { "employeeNum","00112233" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(1, result->size());
}

TEST_F(TestEmployeeNumSearch, TestWrongNum) {
	auto searcher = make_unique<EmployeeNumSearch>();
	Inform inform = { "employeeNum","2015ss1299" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}

TEST_F(TestEmployeeNumSearch, TestWrongColumn) {
	auto searcher = make_unique<EmployeeNumSearch>();
	Inform inform = { "cl","2015123099" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}