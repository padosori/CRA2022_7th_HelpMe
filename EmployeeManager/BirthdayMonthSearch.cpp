#include "BirthdayMonthSearch.h"
#include "EmployeeManagement.h"

unique_ptr<vector<Employee>> BirthdayMonthSearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto results = make_unique<vector<Employee>>();
	results->clear();

	if (condition.column != "birthday_month") {
		return move(results);
	}

	for (auto& employee : employee_mgmt.getMap()) {
		if (employee.second != nullptr && employee.second->birthday_month == condition.value) {
			results->emplace_back(*(employee.second));
		}
	}

	return move(results);
}
