#include "MiddlePhoneNumSearch.h"

unique_ptr<vector<Employee>> MiddlePhoneNumSearch::search(EmployeeMap& employee_map, Inform condition)
{
	auto result = std::make_unique<vector<Employee>>();
	result->clear();
	if (condition.column != "phoneNum_middle") return move(result);
	for (auto& employee : employee_map) {
		if (employee.second != nullptr && employee.second->mid_phone_num == condition.value) result->emplace_back(*(employee.second));
	}
	return move(result);
}
