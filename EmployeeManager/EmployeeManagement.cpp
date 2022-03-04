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

	auto ret = employee_map.insert(make_pair(employee.employee_num, employee));

	if (ret.second == false) {
		throw invalid_argument("fail to add employee");
	}
}

unique_ptr<vector<Employee>> EmployeeManagement::deleteEmployee(Search& searcher, const Inform info) {
	auto employees = make_unique<vector<Employee>>();
	auto search_result = searcher.search(employee_map, info);

	if (0 == search_result->size()) {
		throw invalid_argument("Can't find Employee");
	}

	for (auto& employee : *search_result) {
		employees->emplace_back(employee);
		employee_map.erase(employee.employee_num);
	}
	return move(employees);
}

unique_ptr<vector<Employee>> EmployeeManagement::searchEmployee(Search& searcher, const Inform info) {
	auto employees = make_unique<vector<Employee>>();
	return move(employees);
}

unique_ptr<vector<Employee>> EmployeeManagement::modifyEmployee(Search& searcher, const Inform search_info, const Inform modify_info) {
	auto employees = make_unique<vector<Employee>>();
	return move(employees);
}

const size_t EmployeeManagement::getEmployeeCount() const {
	return employee_map.size();
}

void EmployeeManagement::clearEmployee() {
	employee_map.clear();
}