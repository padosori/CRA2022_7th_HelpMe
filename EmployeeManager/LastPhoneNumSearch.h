#pragma once
#include "Search.h"
#include "EmployeeManagement.h"

class LastPhoneNumSearch : public Search {
public:
	virtual unique_ptr<vector<Employee>> search(EmployeeManagement& employee_mgmt, Inform condition) override;
};