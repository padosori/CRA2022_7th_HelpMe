#include "NameSearch.h"

unique_ptr<vector<Employee>> NameSearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto result = std::make_unique<vector<Employee>>();
	result->clear();
	if (condition.column != "name") return move(result);
	for (auto& employee : employee_mgmt.getMap()) {
		if (employee.second->name == condition.value) result->emplace_back(*(employee.second));
	}
	return move(result);
}