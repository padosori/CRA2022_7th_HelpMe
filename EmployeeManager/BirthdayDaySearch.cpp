#include "BirthdayDaySearch.h"

unique_ptr<vector<Employee>> BirthdayDaySearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto is_match = [condition] (Employee& employee) -> bool { return employee.birthday_day == condition.value; };
	auto results = employee_mgmt.searchList("birthday_day", condition, is_match);
	return move(results);
}
