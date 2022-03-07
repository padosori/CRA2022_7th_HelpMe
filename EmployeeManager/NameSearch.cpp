#include "NameSearch.h"

unique_ptr<vector<Employee>> NameSearch::search(EmployeeMap& employee_map, Inform condition) {
	auto result = std::make_unique<vector<Employee>>();
	result->clear();
	if (condition.column != "name") return move(result);
	for (auto& employee : employee_map) {
		if (employee.second->name == condition.value) result->emplace_back(*(employee.second));
	}
	return move(result);
}