#include "pch.h"
#include "../EmployeeManager/Employee.h"
#include "../EmployeeManager/EmployeeManagement.cpp"

TEST(EmployeeManagerTest, ProcessCMD) {
	EmployeeManagement employee_management;
	Employee employee;
	vector<int> options;
	vector<Inform> informs;

	EXPECT_NO_THROW(employee_management.processCmd(0, options, informs));
}

TEST(EmployeeManagerTest, Add) {
	EmployeeManagement employee_management;
	Employee employee;

	ASSERT_TRUE(employee_management.addEmployee(employee));
}

TEST(EmployeeManagerTest, Delete) {
	EmployeeManagement employee_management;
	Employee employee;
	Inform info;
	unique_ptr<vector<Employee>> employees;

	EXPECT_NO_THROW(employees = employee_management.deleteEmployee(info));
	ASSERT_NE(employees, nullptr);
	ASSERT_EQ(employees->size(), 0);
}

TEST(EmployeeManagerTest, Search) {
	EmployeeManagement employee_management;
	Employee employee;
	Inform info;
	unique_ptr<vector<Employee>> employees;

	EXPECT_NO_THROW(employees = employee_management.searchEmployee(info));
	ASSERT_NE(employees, nullptr);
	ASSERT_EQ(employees->size(), 0);
}


TEST(EmployeeManagerTest, Modify) {
	EmployeeManagement employee_management;
	Employee employee;
	Inform search_info;
	Inform modify_info;
	unique_ptr<vector<Employee>> employees;

	EXPECT_NO_THROW(employees = employee_management.modifyEmployee(search_info, modify_info));
	ASSERT_NE(employees, nullptr);
	ASSERT_EQ(employees->size(), 0);
}
