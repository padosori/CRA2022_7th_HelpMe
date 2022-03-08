#include "BirthdayMonthSearch.h"

unique_ptr<vector<Employee>> BirthdayMonthSearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto is_match = [condition](Employee& employee) -> bool { return employee.birthday_month == condition.value; };
	auto results = employee_mgmt.searchList("birthday_month", condition, is_match);
	return move(results);
}
