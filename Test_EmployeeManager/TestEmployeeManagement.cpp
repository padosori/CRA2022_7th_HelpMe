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


TEST(EmployeeManagerTest, GetEmployeeCount) {
	vector<Employee> employees;

	employees.push_back(Employee{ "11111111", "JAEMYUNG LEE", "JAEMYUNG", "LEE", "010-1111-1111", "1111", "1111", "19641222",
								  "1964", "12", "22", "CL1", "ADV" });
	employees.push_back(Employee{ "22222222", "SUKYEOL YOON", "SUKYEOL", "YOON", "010-2222-2222", "2222", "2222", "19601218",
								  "1960", "12", "18", "CL2", "PRO" });
	employees.push_back(Employee{ "33333333", "SANGJUNG SIM", "SANGJUNG", "SIM", "010-3333-3333", "3333", "3333", "19590404",
								  "1959", "04", "04", "CL3", "EX" });
	employees.push_back(Employee{ "44444444", "CHEOLSOO AHN", "CHEOLSOO", "AHN", "010-4444-4444", "4444", "4444", "19620226",
								  "1962", "02", "26", "CL4", "ADV" });
	employees.push_back(Employee{ "80808080", "JUNHO OH", "JUNHO", "OH", "010-5555-5555", "5555", "5555", "19750620", "1975",
								  "06", "20", "CL1", "PRO" });
	employees.push_back(Employee{ "90909090", "KYUNGYOUNG HUH", "KYUNGYOUNG", "HUH", "010-6666-6666", "6666", "6666",
								  "19470713", "1947", "07", "13", "CL2", "EX" });

	EmployeeManagement employee_management;

	for (auto& employee : employees) {
		EXPECT_NO_THROW(employee_management.addEmployee(employee));
	}

	ASSERT_EQ(employee_management.getEmployeeCount(), 6);
}


TEST(EmployeeManagerTest, Add) {
	vector<Employee> employees;

	employees.push_back(Employee{ "11111111", "JAEMYUNG LEE", "JAEMYUNG", "LEE", "010-1111-1111", "1111", "1111", "19641222",
								  "1964", "12", "22", "CL1", "ADV"});
	employees.push_back(Employee{ "22222222", "SUKYEOL YOON", "SUKYEOL", "YOON", "010-2222-2222", "2222", "2222", "19601218",
								  "1960", "12", "18", "CL2", "PRO" });
	employees.push_back(Employee{ "33333333", "SANGJUNG SIM", "SANGJUNG", "SIM", "010-3333-3333", "3333", "3333", "19590404",
								  "1959", "04", "04", "CL3", "EX" });
	employees.push_back(Employee{ "44444444", "CHEOLSOO AHN", "CHEOLSOO", "AHN", "010-4444-4444", "4444", "4444", "19620226",
								  "1962", "02", "26", "CL4", "ADV"});
	employees.push_back(Employee{ "80808080", "JUNHO OH", "JUNHO", "OH", "010-5555-5555", "5555", "5555", "19750620", "1975",
								  "06", "20", "CL1", "PRO"});
	employees.push_back(Employee{ "90909090", "KYUNGYOUNG HUH", "KYUNGYOUNG", "HUH", "010-6666-6666", "6666", "6666",
								  "19470713", "1947", "07", "13", "CL2", "EX"});

	EmployeeManagement employee_management;

	for (auto& employee : employees) {
		EXPECT_NO_THROW(employee_management.addEmployee(employee));
	}

	ASSERT_EQ(employee_management.getEmployeeCount(), 6);
}

TEST(EmployeeManagerTest, AddFail) {
	EmployeeManagement employee_management;

	Employee employee{ "11111111", "GILDONG HONG", "CL1", "010-1111-1111", "15000101", "ADV" };

	EXPECT_NO_THROW(employee_management.addEmployee(employee));
	EXPECT_THROW(employee_management.addEmployee(employee), invalid_argument);

	employee = { "", "", "", "", "", "" };
	EXPECT_THROW(employee_management.addEmployee(employee), invalid_argument);
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
