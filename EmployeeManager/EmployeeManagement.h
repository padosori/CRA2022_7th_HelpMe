#pragma once

#include <string>
#include <map>
#include <vector>
#include <functional>
#include "Employee.h"
#include "Search.h"
#include "SearchFactory.h"
#include "CmdFactory.h"

using namespace std;

class EmployeeManagement {
public:
	unique_ptr<vector<Employee>> processCmd(Command command, vector<Option> options, vector<Inform> informs);

	unique_ptr<vector<Employee>> searchList(string column_name, Inform condition, function<bool(Employee&)> lambda);

	void addEmployee(unique_ptr<Employee> employee);

	void modifyEmployeeValue(Employee& employee, const Inform info);

	const size_t getEmployeeCount() const;

	void clearEmployee();

	string printCurrentCmd(Command command, vector<Option> options, vector<Inform> informs);

	bool insert(pair<string, unique_ptr<Employee>> element) {
		return employee_map.insert(move(element)).second;
	}

	void erase(string key) {
		employee_map.erase(key);
	}

	size_t count(string key) {
		return employee_map.count(key);
	}

	Employee* find(string key) {
		auto it = employee_map.find(key);
		if (it == employee_map.end()) return nullptr;
		return it->second.get();
	}

private:
	EmployeeMap employee_map;
	SearchFactory search_factory;
	EmployeeListCmdFactory cmd_factory;
};