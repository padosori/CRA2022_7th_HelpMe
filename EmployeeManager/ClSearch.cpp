#include "ClSearch.h"

unique_ptr<vector<Employee>> ClSearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto results = make_unique<vector<Employee>>();
	results->clear();

	if (condition.column != "cl") {
		return move(results);
	}

	for (auto& employee : employee_mgmt.getMap()) {
		if (employee.second != nullptr && employee.second->cl == condition.value) {
			results->emplace_back(*(employee.second));
		}
	}

	return move(results);
}
