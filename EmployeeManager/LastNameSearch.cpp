#include "LastNameSearch.h"

unique_ptr<vector<Employee>> LastNameSearch::search(EmployeeManagement& employee_mgmt, Inform condition)
{
	auto is_match = [condition](Employee& employee) -> bool { return employee.last_name == condition.value; };
	auto results = employee_mgmt.searchList("name_last", condition, is_match);
	return move(results);
}
