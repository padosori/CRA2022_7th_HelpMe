#pragma once

#include <vector>
#include <memory>
#include "Employee.h"
#include "Search.h"

class EmployeeManagement;

class EmployeeListCmd {
public:
	virtual unique_ptr<vector<Employee>> process(EmployeeManagement& employee_mgmt, Search& searcher, const vector<Inform> informs) = 0;
};