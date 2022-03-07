#pragma once

#include <vector>
#include <memory>
#include "Employee.h"
class Search {
public:
	virtual unique_ptr<vector<Employee>> search(EmployeeMap& employee_map, Inform condition) = 0;
private:

};