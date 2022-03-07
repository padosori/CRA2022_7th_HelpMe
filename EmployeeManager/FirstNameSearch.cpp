#include "FirstNameSearch.h"

unique_ptr<vector<Employee>> FirstNameSearch::search(EmployeeMap& employee_map, Inform condition)
{
	auto result = std::make_unique<vector<Employee>>();
	result->clear();
	if (condition.column != "name_first") return move(result);
	for (auto& employee : employee_map) {
		if (employee.second->first_name == condition.value) {
			result->emplace_back(*(employee.second));
		}
	}
	return move(result);
}