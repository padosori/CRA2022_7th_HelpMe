#include "NameSearch.h"

unique_ptr<vector<Employee>> NameSearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto is_match = [condition](Employee& employee) -> bool { return employee.name == condition.value; };
	auto results = employee_mgmt.searchList("name", condition, is_match);
	return move(results);
}