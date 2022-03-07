#include "BirthdayDaySearch.h"

unique_ptr<vector<Employee>> BirthdayDaySearch::search(EmployeeMap& employee_map, Inform condition) {
	auto results = make_unique<vector<Employee>>();
	results->clear();

	if (condition.column != "birthday_day") {
		return move(results);
	}

	for (auto& employee : employee_map) {
		if (employee.second->birthday_day == condition.value) {
			results->emplace_back(*(employee.second));
		}
	}

	return move(results);
}
