#include "pch.h"
#include "../EmployeeManager/Employee.h"
#include "../EmployeeManager/Search.h"
#include "../EmployeeManager/ClSearch.h"
#include "../EmployeeManager/EmployeeManagement.cpp"

class TestEmployeeManagement : public ::testing::Test {
protected:
	void SetUp() override {
		employees.push_back(Employee{ "11111111", "JAEMYUNG LEE", "JAEMYUNG", "LEE",
									  "010-1111-1111", "1111", "1111",
									  "19641222", "1964", "12", "22",
									  "CL1", "ADV" });
		employees.push_back(Employee{ "22222222", "SUKYEOL YOON", "SUKYEOL", "YOON",
									  "010-2222-2222", "2222", "2222",
									  "19601218", "1960", "12", "18",
									  "CL2", "PRO" });
		employees.push_back(Employee{ "33333333", "SANGJUNG SIM", "SANGJUNG", "SIM",
									  "010-3333-3333", "3333", "3333",
									  "19590404", "1959", "04", "04",
									  "CL3", "EX" });
		employees.push_back(Employee{ "44444444", "CHEOLSOO AHN", "CHEOLSOO", "AHN",
									  "010-4444-4444", "4444", "4444",
									  "19620226", "1962", "02", "26",
									  "CL4", "ADV" });
		employees.push_back(Employee{ "80808080", "JUNHO OH", "JUNHO", "OH",
									  "010-5555-5555", "5555", "5555",
									  "19750620", "1975", "06", "20",
									  "CL1", "PRO" });
		employees.push_back(Employee{ "90909090", "KYUNGYOUNG HUH", "KYUNGYOUNG", "HUH",
									  "010-6666-6666", "6666", "6666",
									  "19470713", "1947", "07", "13",
									  "CL2", "EX" });

		for (auto& employee : employees) {
			EXPECT_NO_THROW(employee_management.addEmployee(employee));
		}
	}

	void TearDown() override {
		employee_management.clearEmployee();
	}

	EmployeeManagement employee_management;
	vector<Employee> employees;
};


TEST_F(TestEmployeeManagement, ProcessCMD) {
	vector<int> options;
	vector<Inform> informs;

	EXPECT_NO_THROW(employee_management.processCmd(0, options, informs));
}


TEST_F(TestEmployeeManagement, GetEmployeeCount) {
	ASSERT_EQ(employee_management.getEmployeeCount(), 6);
}

TEST_F(TestEmployeeManagement, ClearEmployee) {
	EXPECT_EQ(employee_management.getEmployeeCount(), 6);
	employee_management.clearEmployee();
	EXPECT_EQ(employee_management.getEmployeeCount(), 0);
}


TEST_F(TestEmployeeManagement, Add) {
	ASSERT_EQ(employee_management.getEmployeeCount(), 6);
}

TEST_F(TestEmployeeManagement, AddFail) {
	Employee employee{ "12341234", "GILDONG HONG", "GILDONG", "HONG",
					   "010-1234-1234", "1234", "66612346",
					   "15000101", "1500", "01", "01",
					   "CL2", "EX" };

	EXPECT_NO_THROW(employee_management.addEmployee(employee));
	EXPECT_THROW(employee_management.addEmployee(employee), invalid_argument);

	employee = { "", "", "", "", "", "" };
	EXPECT_THROW(employee_management.addEmployee(employee), invalid_argument);
}

TEST_F(TestEmployeeManagement, Delete) {
	ClSearch searcher;
	unique_ptr<vector<Employee>> employees;

	Inform info = {"cl", "CL1"};
	EXPECT_NO_THROW(employees = employee_management.deleteEmployee(searcher, info));
	EXPECT_EQ(employees->size(), 2);
	EXPECT_EQ(employee_management.getEmployeeCount(), 4);

	info = { "cl", "CL2" };
	EXPECT_NO_THROW(employees = employee_management.deleteEmployee(searcher, info));
	EXPECT_EQ(employees->size(), 2);
	EXPECT_EQ(employee_management.getEmployeeCount(), 2);

	info = { "cl", "CL3" };
	EXPECT_NO_THROW(employees = employee_management.deleteEmployee(searcher, info));
	EXPECT_EQ(employees->size(), 1);
	EXPECT_EQ(employee_management.getEmployeeCount(), 1);

	info = { "cl", "CL4" };
	EXPECT_NO_THROW(employees = employee_management.deleteEmployee(searcher, info));
	EXPECT_EQ(employees->size(), 1);
	EXPECT_EQ(employee_management.getEmployeeCount(), 0);
}

TEST_F(TestEmployeeManagement, DeleteFail) {
	ClSearch searcher;

	EXPECT_EQ(employee_management.getEmployeeCount(), 6);
	Inform info = { "cl", "CL5" };
	EXPECT_THROW(employee_management.deleteEmployee(searcher, info), invalid_argument);
	EXPECT_EQ(employee_management.getEmployeeCount(), 6);
}


TEST_F(TestEmployeeManagement, Search) {
	Inform info;
	ClSearch searcher;
	unique_ptr<vector<Employee>> employees;

	EXPECT_NO_THROW(employees = employee_management.searchEmployee(searcher, info));
	ASSERT_NE(employees, nullptr);
	ASSERT_EQ(employees->size(), 0);
}


TEST_F(TestEmployeeManagement, Modify) {
	Inform search_info;
	Inform modify_info;
	ClSearch searcher;
	unique_ptr<vector<Employee>> employees;

	EXPECT_NO_THROW(employees = employee_management.modifyEmployee(searcher, search_info, modify_info));
	ASSERT_NE(employees, nullptr);
	ASSERT_EQ(employees->size(), 0);
}
