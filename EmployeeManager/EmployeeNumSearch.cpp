#include "EmployeeNumSearch.h"

unique_ptr<vector<Employee>> EmployeeNumSearch::search(EmployeeMap& employee_map, Inform condition) {
	auto result = std::make_unique<vector<Employee>>();
	result->clear();

	if (!isCorrectColumn(condition.column)) {
		return move(result);
	}

	if (employee_map.count(condition.value) == 1 && employee_map[condition.value] != nullptr) {
		result->emplace_back(*(employee_map[condition.value]));
	}
	return move(result);
}

bool EmployeeNumSearch::isCorrectColumn(string condition_column) {
	return(condition_column == "employeeNum");
}

bool EmployeeNumSearch::isMatched(Employee& employee, string condition_value) {
	return false;
}
