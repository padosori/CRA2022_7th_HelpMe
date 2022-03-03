#pragma once

#include <map>
#include <vector>
#include <memory>
#include "Employee.h"
class Search {
public:
	virtual unique_ptr<vector<Employee>> search(map<std::string, Employee>& employee_map, Inform condition) = 0;
private:

};