#include "LastPhoneNumSearch.h"

unique_ptr<vector<Employee>> LastPhoneNumSearch::search(EmployeeManagement& employee_mgmt, Inform condition)
{
	auto is_match = [condition](Employee& employee) -> bool { return employee.last_phone_num == condition.value; };
	auto results = employee_mgmt.searchList("phoneNum_last", condition, is_match);
	return move(results);
}
