#include "CertiSearch.h"

unique_ptr<vector<Employee>> CertiSearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto is_match = [condition](Employee& employee) -> bool { return employee.certi == condition.value; };
	auto results = employee_mgmt.searchList("certi", condition, is_match);
	return move(results);
}
