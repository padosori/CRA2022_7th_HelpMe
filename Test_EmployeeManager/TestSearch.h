#pragma once
#include "pch.h"
#include <memory>
#include "../EmployeeManager/Employee.h"

class TestSearch : public ::testing::Test {
protected:
	void SetUp() override {
		employeeMap = make_unique<map<std::string, Employee>>();

		employees.push_back(Employee{ "00112233", "Gildong Hong", "Gildong", "Hong",
			"010-1234-5678", "1234", "5678",
			"20000102", "2000", "01", "02",
			"CL1", "PRO" });

		employees.push_back(Employee{ "01112233", "Choonhyang Seong", "Choonhyang", "Seong",
			"010-4321-5678", "4321", "5678",
			"20010103", "2001", "01", "03",
			"CL2", "PRO" });

		employees.push_back(Employee{ "01001122", "Gyoungrae Hong", "Gyoungrae", "Hong",
			"010-1234-6789", "1234", "5678",
			"20000203", "2000", "02", "03",
			"CL1", "EX" });

		employees.push_back(Employee{ "99112233", "Gyoungrae Hong", "Gyoungrae", "Hong",
			"010-0000-0001", "0000", "0001",
			"19990203", "1999", "02", "03",
			"CL3", "EX" });

		employeeMap->insert({ "00112233", employees[0] });
		employeeMap->insert({ "01112233", employees[1] });
		employeeMap->insert({ "01001122", employees[2] });
		employeeMap->insert({ "99112233", employees[3] });
	}

	void TearDown() override {
		employeeMap->clear();
	}

	unique_ptr<map<std::string, Employee>> employeeMap;
	vector<Employee> employees;
};
