#include "BirthdaySearch.h"

unique_ptr<vector<Employee>> BirthdaySearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto is_match = [condition](Employee& employee) -> bool { return employee.birthday == condition.value; };
	auto results = employee_mgmt.searchList("birthday", condition, is_match);
	return move(results);
}
