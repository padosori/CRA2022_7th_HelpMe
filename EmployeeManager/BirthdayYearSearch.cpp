#include "BirthdayYearSearch.h"

unique_ptr<vector<Employee>> BirthdayYearSearch::search(EmployeeMap& employee_map, Inform condition) {
	auto results = make_unique<vector<Employee>>();
	results->clear();

	if (condition.column != "birthday_year") {
		return move(results);
	}

	for (auto& employee : employee_map) {
		if (employee.second != nullptr && employee.second->birthday_year == condition.value) {
			results->emplace_back(*(employee.second));
		}
	}

	return move(results);
}
