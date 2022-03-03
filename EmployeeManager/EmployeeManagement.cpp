#include <memory>
#include <utility>
#include <stdexcept>
#include "EmployeeManagement.h"

using namespace std;

void EmployeeManagement::processCmd(int command, vector<int> options, vector<Inform> informs) {

}

void EmployeeManagement::addEmployee(Employee& employee) {
	if (employee.employee_num == "") {
		throw invalid_argument("invalid employee information");
		return;
	}

	auto ret = employee_map_.insert(make_pair(employee.employee_num, employee));

	if (ret.second == false) {
		throw invalid_argument("fail to add employee");
	}
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

const size_t EmployeeManagement::getEmployeeCount() const {
	return employee_map_.size();
}