#include "MiddlePhoneNumSearch.h"

unique_ptr<vector<Employee>> MiddlePhoneNumSearch::search(EmployeeManagement& employee_mgmt, Inform condition)
{
	auto is_match = [condition](Employee& employee) -> bool { return employee.mid_phone_num == condition.value; };
	auto results = employee_mgmt.searchList("phoneNum_middle", condition, is_match);
	return move(results);
}
