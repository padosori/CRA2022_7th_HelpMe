#include "LastNameSearch.h"

unique_ptr<vector<Employee>> LastNameSearch::search(EmployeeMap& employee_map, Inform condition)
{
	auto result = std::make_unique<vector<Employee>>();
	result->clear();
	if (condition.column != "name_last") return move(result);
	for (auto& employee : employee_map) {
		if (employee.second->last_name == condition.value) result->emplace_back(*(employee.second));
	}
	return move(result);
}
