#pragma once
#include "Search.h"
#include "Employee.h"

class FirstNameSearch : public Search {
public:
	virtual unique_ptr<vector<Employee>> search(map<std::string, Employee>& employee_map, Inform condition) override;
};