#include "BirthdayYearSearch.h"

unique_ptr<vector<Employee>> BirthdayYearSearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto is_match = [condition](Employee& employee) -> bool { return employee.birthday_year == condition.value; };
	auto results = employee_mgmt.searchList("birthday_year", condition, is_match);
	return move(results);
}
