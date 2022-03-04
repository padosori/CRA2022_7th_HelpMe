#include "BirthdayMonthSearch.h"

unique_ptr<vector<Employee>> BirthdayMonthSearch::search(map<std::string, Employee>& employee_map, Inform condition) {
	auto results = make_unique<vector<Employee>>();
	results->clear();

	if (condition.column != "birthday_month") {
		return move(results);
	}

	for (auto& employee : employee_map) {
		if (employee.second.birthday_month == condition.value) {
			results->emplace_back(employee.second);
		}
	}

	return move(results);
}
