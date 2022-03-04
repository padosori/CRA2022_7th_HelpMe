#pragma once
#include "Search.h"

class CertiSearch : public Search {
public:
	virtual unique_ptr<vector<Employee>> search(map<std::string, Employee>& employee_map, Inform condition) override;
};
