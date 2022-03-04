#include "pch.h"
#include "TestSearch.h"
#include "../EmployeeManager/NameSearch.cpp"

using TestNameSearch = TestSearch;

TEST_F(TestNameSearch, TestSearchOneItem) {
	auto searcher = make_unique<NameSearch>();
	Inform inform = { "name", "Gildong Hong" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("Gildong Hong", (*result)[0].name);
}

TEST_F(TestNameSearch, TestWrongName) {
	auto searcher = make_unique<NameSearch>();
	Inform inform = { "name", "ENDMA" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}

TEST_F(TestNameSearch, TestWrongColumn) {
	auto searcher = make_unique<NameSearch>();
	Inform inform = { "cl","2015123099" };
	auto result = searcher->search(*employeeMap, inform);
	EXPECT_EQ(0, result->size());
}