#include "EmployeeNumSearch.h"

unique_ptr<vector<Employee>> EmployeeNumSearch::search(map<std::string, Employee>& employee_map, Inform condition) {
	auto result = std::make_unique<vector<Employee>>();
	result->clear();
	if (condition.column != "employeeNum") return move(result);
	if (employee_map.count(condition.value) == 1) result->emplace_back(employee_map[condition.value]);	
	return move(result);
}