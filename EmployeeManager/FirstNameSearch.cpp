#include "FirstNameSearch.h"

unique_ptr<vector<Employee>> FirstNameSearch::search(EmployeeManagement& employee_mgmt, Inform condition)
{
	auto result = std::make_unique<vector<Employee>>();
	result->clear();
	if (condition.column != "name_first") return move(result);

	for (auto& employee : employee_mgmt.getMap()) {
		if (employee.second != nullptr && employee.second->first_name == condition.value) {
			result->emplace_back(*(employee.second));
		}
	}
	return move(result);
}