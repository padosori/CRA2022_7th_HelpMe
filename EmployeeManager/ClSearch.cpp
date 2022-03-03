#include "ClSearch.h"

unique_ptr<vector<Employee>> ClSearch::search(map<std::string, Employee>& employee_map, Inform condition) {
	auto results = make_unique<vector<Employee>>();
	results->clear();

	if (condition.column != "cl") {
		return move(results);
	}

	for (auto& employee : employee_map) {
		if (employee.second.cl == condition.value) {
			results->emplace_back(employee.second);
		}
	}

	return move(results);
}
