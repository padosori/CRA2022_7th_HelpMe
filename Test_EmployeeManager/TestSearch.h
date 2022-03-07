#pragma once
#include "pch.h"
#include <memory>
#include "../EmployeeManager/Employee.h"

class TestSearch : public ::testing::Test {
protected:
	void SetUp() override {
		employeeMap = make_unique<EmployeeMap>();

		employeeMap->insert({ "2000112233",
			move(make_unique<Employee>(Employee{"2000112233", "Gildong Hong", "Gildong", "Hong",
				"010-1234-5678", "1234", "5678",
				"20000102", "2000", "01", "02",
				"CL1", "PRO" })) });

		employeeMap->insert({ "2001112233",
			move(make_unique<Employee>(Employee{"2001112233", "Choonhyang Seong", "Choonhyang", "Seong",
				"010-4321-5678", "4321", "5678",
				"20010103", "2001", "01", "03",
				"CL2", "PRO" })) });

		employeeMap->insert({ "2001001122",
			move(make_unique<Employee>(Employee{"2001001122", "Gyoungrae Hong", "Gyoungrae", "Hong",
				"010-1234-6789", "1234", "6789",
				"20000203", "2000", "02", "03",
				"CL1", "EX" })) });

		employeeMap->insert({ "1999112233",
			move(make_unique<Employee>(Employee{"1999112233", "Gyoungrae Hong", "Gyoungrae", "Hong",
				"010-0000-0001", "0000", "0001",
				"19990203", "1999", "02", "03",
				"CL3", "EX" })) });
	}

	void TearDown() override {
		employeeMap->clear();
	}

	unique_ptr<EmployeeMap> employeeMap;
};
