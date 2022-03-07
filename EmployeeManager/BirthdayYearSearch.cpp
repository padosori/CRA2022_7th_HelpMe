#include "BirthdayYearSearch.h"
#include "EmployeeManagement.h"

unique_ptr<vector<Employee>> BirthdayYearSearch::search(EmployeeManagement& employee_mgmt, Inform condition) {
	auto results = make_unique<vector<Employee>>();
	results->clear();

	if (condition.column != "birthday_year") {
		return move(results);
	}

	for (auto& employee : employee_mgmt.getMap()) {
		if (employee.second->birthday_year == condition.value) {
			results->emplace_back(*(employee.second));
		}
	}

	return move(results);
}
