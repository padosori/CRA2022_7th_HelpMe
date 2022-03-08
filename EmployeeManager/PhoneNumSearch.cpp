#include "PhoneNumSearch.h"

unique_ptr<vector<Employee>> PhoneNumSearch::search(EmployeeManagement& employee_mgmt, Inform condition)
{
	auto is_match = [condition](Employee& employee) -> bool { return employee.phone_num == condition.value; };
	auto results = employee_mgmt.searchList("phoneNum", condition, is_match);
	return move(results);
}
