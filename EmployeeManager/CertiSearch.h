#pragma once
#include "Search.h"

class CertiSearch : public Search {
public:
	virtual unique_ptr<vector<Employee>> search(EmployeeMap& employee_map, Inform condition) override;
};
