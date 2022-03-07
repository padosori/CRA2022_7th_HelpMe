#pragma once
#include "Search.h"

class BirthdayMonthSearch : public Search {
public:
	virtual unique_ptr<vector<Employee>> search(EmployeeMap& employee_map, Inform condition) override;
};
