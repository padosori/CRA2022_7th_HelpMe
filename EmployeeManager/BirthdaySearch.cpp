#include "BirthdaySearch.h"

unique_ptr<vector<Employee>> BirthdaySearch::search(map<std::string, Employee>& employee_map, Inform condition) {
	auto results = make_unique<vector<Employee>>();
	results->clear();

	if (condition.column != "birthday") {
		return move(results);
	}

	for (auto& employee : employee_map) {
		if (employee.second.birthday == condition.value) {
			results->emplace_back(employee.second);
		}
	}

	return move(results);
}
