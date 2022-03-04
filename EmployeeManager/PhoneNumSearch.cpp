#include "PhoneNumSearch.h"

unique_ptr<vector<Employee>> PhoneNumSearch::search(map<std::string, Employee>& employee_map, Inform condition)
{
	auto result = std::make_unique<vector<Employee>>();
	result->clear();
	if (condition.column != "phoneNum") return move(result);
	for (auto employee : employee_map) {
		if (employee.second.phone_num == condition.value) result->emplace_back(employee.second);
	}
	return move(result);
}
