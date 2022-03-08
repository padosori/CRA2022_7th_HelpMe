#include "pch.h"
#include "../EmployeeManager/SearchFactory.cpp"

class TestSearchFactory : public ::testing::Test {
protected:
	void SetUp() override {
		search_factory = make_unique<SearchFactory>();

		employee_management.insert({ "00112233",
			move(make_unique<Employee>(Employee{"00112233", "Gildong Hong", "Gildong", "Hong",
				"010-1234-5678", "1234", "5678",
				"20000102", "2000", "01", "02",
				"CL1", "PRO" })) });

		employee_management.insert({ "01112233",
			move(make_unique<Employee>(Employee{"01112233", "Choonhyang Seong", "Choonhyang", "Seong",
				"010-4321-5678", "4321", "5678",
				"20010103", "2001", "01", "03",
				"CL2", "PRO" })) });

		employee_management.insert({ "01001122",
			move(make_unique<Employee>(Employee{"01001122", "Gyoungrae Hong", "Gyoungrae", "Hong",
				"010-1234-6789", "1234", "6789",
				"20000203", "2000", "02", "03",
				"CL1", "EX" })) });

		employee_management.insert({ "99112233",
			move(make_unique<Employee>(Employee{"99112233", "Gyoungrae Hong", "Gyoungrae", "Hong",
				"010-0000-0001", "0000", "0001",
				"19990203", "1999", "02", "03",
				"CL3", "EX" })) });
	}

	void TearDown() override {
		employee_management.clearEmployee();
	}

	vector<Employee> employees;
	shared_ptr<Search> searcher;
	unique_ptr<SearchFactory> search_factory;
	EmployeeManagement employee_management;
};

TEST_F(TestSearchFactory, TestNameSearch) {
	searcher = search_factory->getSearch("name");
	auto result = searcher->search(employee_management, { "name", "Gyoungrae Hong" });
	EXPECT_EQ(2, result->size());
	EXPECT_EQ("Gyoungrae Hong", (*result)[0].name);
}

TEST_F(TestSearchFactory, TestFirstNameSearch) {
	searcher = search_factory->getSearch("name_first");
	auto result = searcher->search(employee_management, { "name_first", "Gildong" });
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("Gildong Hong", (*result)[0].name);
}

TEST_F(TestSearchFactory, TestLastNameSearch) {
	searcher = search_factory->getSearch("name_last");
	auto result = searcher->search(employee_management, { "name_last", "Seong" });
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("Choonhyang Seong", (*result)[0].name);
}

TEST_F(TestSearchFactory, TestPhoneNumSearch) {
	searcher = search_factory->getSearch("phoneNum");
	auto result = searcher->search(employee_management, { "phoneNum", "010-4321-5678" });
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("010-4321-5678", (*result)[0].phone_num);
}

TEST_F(TestSearchFactory, TestMiddelPhoneNumSearch) {
	searcher = search_factory->getSearch("phoneNum_middle");
	auto result = searcher->search(employee_management, { "phoneNum_middle", "0000" });
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("010-0000-0001", (*result)[0].phone_num);
}

TEST_F(TestSearchFactory, TestLastPhoneNumSearch) {
	searcher = search_factory->getSearch("phoneNum_last");
	auto result = searcher->search(employee_management, { "phoneNum_last", "0001" });
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("010-0000-0001", (*result)[0].phone_num);
}

TEST_F(TestSearchFactory, TestBirthdaySearch) {
	searcher = search_factory->getSearch("birthday");
	auto result = searcher->search(employee_management, { "birthday", "19990203" });
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("19990203", (*result)[0].birthday);
}

TEST_F(TestSearchFactory, TestBirthdayYearSearch) {
	searcher = search_factory->getSearch("birthday_year");
	auto result = searcher->search(employee_management, { "birthday_year", "1999" });
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("19990203", (*result)[0].birthday);
}

TEST_F(TestSearchFactory, TestBirthdayMonthSearch) {
	searcher = search_factory->getSearch("birthday_month");
	auto result = searcher->search(employee_management, { "birthday_month", "02" });
	EXPECT_EQ(2, result->size());
	EXPECT_EQ("20000203", (*result)[0].birthday);
}

TEST_F(TestSearchFactory, TestBirthdayDaySearch) {
	searcher = search_factory->getSearch("birthday_day");
	auto result = searcher->search(employee_management, { "birthday_day", "02" });
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("20000102", (*result)[0].birthday);
}

TEST_F(TestSearchFactory, TestEmployeeNumSearch) {
	searcher = search_factory->getSearch("employeeNum");
	auto result = searcher->search(employee_management, { "employeeNum", "00112233" });
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("00112233", (*result)[0].employee_num);
}

TEST_F(TestSearchFactory, TestCertiSearch) {
	searcher = search_factory->getSearch("certi");
	auto result = searcher->search(employee_management, { "certi", "EX" });
	EXPECT_EQ(2, result->size());
	EXPECT_EQ("EX", (*result)[0].certi);
}

TEST_F(TestSearchFactory, TestClSearch) {
	searcher = search_factory->getSearch("cl");
	auto result = searcher->search(employee_management, { "cl", "CL2" });
	EXPECT_EQ(1, result->size());
	EXPECT_EQ("CL2", (*result)[0].cl);
}