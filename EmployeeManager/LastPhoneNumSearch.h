#pragma once
#include "Search.h"
#include "Employee.h"

class LastPhoneNumSearch : public Search {
public:
	virtual unique_ptr<vector<Employee>> search(EmployeeMap& employee_map, Inform condition) override;
};