#pragma once
#include <vector>
#include <memory>
#include "Employee.h"
class Search {
public:
	virtual unique_ptr<vector<Employee>> search(EmployeeMap& employee_map, Inform condition) {
		auto results = make_unique<vector<Employee>>();
		results->clear();

		if (!isCorrectColumn(condition.column)) {
			return move(results);
		}

		for (auto& employee : employee_map) {
			if (employee.second != nullptr && isMatched(*(employee.second), condition.value)) {
				results->emplace_back(*(employee.second));
			}
		}

		return move(results);
	}
protected:
	virtual bool isCorrectColumn(string condition_column) = 0;
	virtual bool isMatched(Employee& employee, string condition_value) = 0;
};