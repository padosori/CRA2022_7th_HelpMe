#pragma once
#include "Search.h"
#include "Employee.h"

class NameSearch : public Search {
public:
	virtual unique_ptr<vector<Employee>> search(EmployeeMap& employee_map, Inform condition) override;
};