#pragma once
#include "Search.h"
#include "EmployeeManagement.h"

class EmployeeNumSearch : public Search {
public:
	virtual unique_ptr<vector<Employee>> search(EmployeeManagement& employee_mgmt, Inform condition) override;

private:


};



