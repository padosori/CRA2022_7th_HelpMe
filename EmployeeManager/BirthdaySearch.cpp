#include "BirthdaySearch.h"

unique_ptr<vector<Employee>> BirthdaySearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto results = make_unique<vector<Employee>>();
	results->clear();

	if (condition.column != "birthday") {
		return move(results);
	}

	for (auto& employee : employee_mgmt.getMap()) {
		if (employee.second != nullptr && employee.second->birthday == condition.value) {
			results->emplace_back(*(employee.second));
		}
	}

	return move(results);
}
