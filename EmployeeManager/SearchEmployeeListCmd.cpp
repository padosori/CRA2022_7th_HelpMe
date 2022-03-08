#include <stdexcept>
#include "SearchEmployeeListCmd.h"
#include "EmployeeManagement.h"

unique_ptr<vector<Employee>> SearchEmployeeListCmd::process(EmployeeManagement& employee_mgmt, Search& searcher, const vector<Inform> informs) {
	auto employees = make_unique<vector<Employee>>();
	auto search_result = searcher.search(employee_mgmt, informs[0]);

	for (auto& employee : *search_result) {
		employees->emplace_back(employee);
	}
	return move(employees);
}