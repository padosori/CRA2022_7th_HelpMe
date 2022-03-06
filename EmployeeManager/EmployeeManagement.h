#pragma once

#include <string>
#include <map>
#include <vector>
#include "Employee.h"
#include "Search.h"

using namespace std;

typedef map<string, Employee> EmployeeMap;

class EmployeeManagement {
public:
	unique_ptr<vector<Employee>> processCmd(Command command, vector<Option> options, vector<Inform> informs);

	void addEmployee(Employee& employee);

	unique_ptr<vector<Employee>> deleteEmployees(Search& searcher, const Inform info);

	unique_ptr<vector<Employee>> searchEmployees(Search& searcher, const Inform info);

	unique_ptr<vector<Employee>> modifyEmployees(Search& searcher, const Inform search_info, const Inform modify_info);

	void modifyEmployeeValue(Employee& employee, const Inform info);

	const size_t getEmployeeCount() const;

	void clearEmployee();
private:
	EmployeeMap employee_map;
};