#include <memory>
#include <utility>
#include "EmployeeManagement.h"

using namespace std;

void EmployeeManagement::processCmd(int command, vector<int> options, vector<Inform> informs) {

}

bool EmployeeManagement::addEmployee(Employee& employee) {
	return true;
}

unique_ptr<vector<Employee>> EmployeeManagement::deleteEmployee(const Inform info) {
	auto employees = make_unique<vector<Employee>>();
	return move(employees);
}

unique_ptr<vector<Employee>> EmployeeManagement::searchEmployee(const Inform info) {
	auto employees = make_unique<vector<Employee>>();
	return move(employees);
}

unique_ptr<vector<Employee>> EmployeeManagement::modifyEmployee(const Inform search_info, const Inform modify_info) {
	auto employees = make_unique<vector<Employee>>();
	return move(employees);
}