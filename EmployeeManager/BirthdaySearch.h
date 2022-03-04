#pragma once
#include "Search.h"

class BirthdaySearch : public Search {
public:
	virtual unique_ptr<vector<Employee>> search(map<std::string, Employee>& employee_map, Inform condition) override;
};
