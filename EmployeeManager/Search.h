#pragma once

#include <vector>
#include <memory>
#include "Employee.h"

class EmployeeManagement;

class Search {
public:
	virtual unique_ptr<vector<Employee>> search(EmployeeManagement& employee_mgmt, Inform condition) = 0;
private:

};