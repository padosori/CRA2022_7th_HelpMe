#pragma once

#include <string>
#include <map>
#include <vector>
#include "Employee.h"

using namespace std;

typedef map<string, Employee> EmployeeMap;

class EmployeeManagement {
public:
	void processCmd(int command, vector<int> options, vector<Inform> informs);

	void addEmployee(Employee& employee);

	unique_ptr<vector<Employee>> deleteEmployee(const Inform info);

	unique_ptr<vector<Employee>> searchEmployee(const Inform info);

	unique_ptr<vector<Employee>> modifyEmployee(const Inform search_info, const Inform modify_info);

	const size_t getEmployeeCount() const;
private:
	EmployeeMap employee_map_;
};