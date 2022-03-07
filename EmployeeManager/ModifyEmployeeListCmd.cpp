#include <stdexcept>
#include "ModifyEmployeeListCmd.h"
#include "EmployeeManagement.h"

unique_ptr<vector<Employee>> ModifyEmployeeListCmd::process(EmployeeManagement& employee_mgmt, Search& searcher, const vector<Inform> informs) {
	auto employees = make_unique<vector<Employee>>();
	auto search_result = searcher.search(employee_mgmt, informs[0]);

	for (auto& employee : *search_result) {
		if (auto found_employee = employee_mgmt.find(employee.employee_num)) {
			employees->emplace_back(employee);
			employee_mgmt.modifyEmployeeValue(*found_employee, informs[1]);
		}
	}
	return move(employees);
}