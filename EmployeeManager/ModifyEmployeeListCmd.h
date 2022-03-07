#pragma once
#include "EmployeeListCmd.h"
#include "EmployeeManagement.h"

class ModifyEmployeeListCmd : public EmployeeListCmd {
public:
	virtual unique_ptr<vector<Employee>> process(EmployeeManagement& employee_mgmt, Search& searcher, const vector<Inform> informs) override;
};
