#pragma once

#include <map>
#include <vector>
#include <memory>
#include "Employee.h"
class Search {
public:
	virtual unique_ptr<vector<Employee>> searchTargetEmployeeList(map<std::string, Employee>& employ_map, Inform inform) = 0;
private:

};