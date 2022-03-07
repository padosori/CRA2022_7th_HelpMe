#include "EmployeeNumSearch.h"

unique_ptr<vector<Employee>> EmployeeNumSearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto result = std::make_unique<vector<Employee>>();
	result->clear();
	if (condition.column != "employeeNum") return move(result);
	if (employee_mgmt.count(condition.value) == 1) {
		result->emplace_back(*(employee_mgmt.getMap()[condition.value]));
	}
	return move(result);
}