#include "FirstNameSearch.h"

unique_ptr<vector<Employee>> FirstNameSearch::search(EmployeeManagement& employee_mgmt, Inform condition)
{
	auto is_match = [condition](Employee& employee) -> bool { return employee.first_name == condition.value; };
	auto results = employee_mgmt.searchList("name_first", condition, is_match);
	return move(results);
}