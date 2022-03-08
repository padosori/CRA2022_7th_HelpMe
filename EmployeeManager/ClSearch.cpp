#include "ClSearch.h"

unique_ptr<vector<Employee>> ClSearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto is_match = [condition](Employee& employee) -> bool { return employee.cl == condition.value; };
	auto results = employee_mgmt.searchList("cl", condition, is_match);
	return move(results);
}
