#include "EmployeeNumSearch.h"

unique_ptr<vector<Employee>> EmployeeNumSearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto result = std::make_unique<vector<Employee>>();
	result->clear();
	if (condition.column != "employeeNum") return move(result);
	if (employee_mgmt.count(condition.value) == 1) {
		auto employee = employee_mgmt.find(condition.value);
		if (employee != nullptr) {
			result->emplace_back(*employee);
		}
	}
	return move(result);
}