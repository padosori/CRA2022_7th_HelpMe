#include <memory>
#include <utility>
#include <stdexcept>
#include <iostream>
#include "EmployeeManagement.h"
#include "ClSearch.h"

using namespace std;

unique_ptr<vector<Employee>> EmployeeManagement::processCmd(
	Command command, vector<Option> options, vector<Inform> informs) {

	if (command == Command::ADD) {
		auto employee = std::make_unique<Employee>();

		for (auto inform : informs) {
			if (inform.column == "employeeNum") { employee->employee_num = inform.value; }
			else if (inform.column == "name") { employee->name = inform.value; }
			else if (inform.column == "name_first") { employee->first_name = inform.value; }
			else if (inform.column == "name_last") { employee->last_name = inform.value; }
			else if (inform.column == "cl") { employee->cl = inform.value; }
			else if (inform.column == "phoneNum") { employee->phone_num = inform.value; }
			else if (inform.column == "phoneNum_middle") { employee->mid_phone_num = inform.value; }
			else if (inform.column == "phoneNum_last") { employee->last_phone_num = inform.value; }
			else if (inform.column == "birthday") { employee->birthday = inform.value; }
			else if (inform.column == "birthday_year") { employee->birthday_year = inform.value; }
			else if (inform.column == "birthday_month") { employee->birthday_month = inform.value; }
			else if (inform.column == "birthday_day") { employee->birthday_day = inform.value; }
			else if (inform.column == "certi") { employee->certi = inform.value; }
			else { throw invalid_argument("Invalid inform.column"); }
		}

		try {
			addEmployee(move(employee));
		} catch (exception& e)  {
			cout << "addEmployee() is failed: " << e.what() <<
				printCurrentCmd(command, options, informs) << endl;
			return nullptr;
		}
		return nullptr;
	}
	else if (command == Command::DEL) {
		unique_ptr<vector<Employee>> result;

		if (informs.size() != 1) {
			cout << "Invalid argument error in deleteEmployees()" <<
				printCurrentCmd(command, options, informs) << endl;
			return nullptr;
		}

		try {
			auto searcher = search_factory.getSearch(informs[0].column);
			result = deleteEmployees(*searcher, informs[0]);
		}
		catch (exception& e) {
			cout << "deleteEmployees() is failed: " << e.what() <<
				printCurrentCmd(command, options, informs) << endl;
			return nullptr;
		}
		return result;
	}
	else if (command == Command::MOD) {
		unique_ptr<vector<Employee>> result;

		if (informs.size() != 2) {
			cout << "Invalid argument error in modifyEmployees()" <<
				printCurrentCmd(command, options, informs) << endl;
			return nullptr;
		}

		try {
			auto searcher = search_factory.getSearch(informs[0].column);
			result = modifyEmployees(*searcher, informs[0], informs[1]);
		}
		catch (exception& e) {
			cout << "modifyEmployees() is failed: " << e.what() <<
				printCurrentCmd(command, options, informs) << endl;
			return nullptr;
		}
		return result;
	}
	else if (command == Command::SCH) {
		unique_ptr<vector<Employee>> result;

		if (informs.size() != 1) {
			cout << "Invalid argument error in searchEmployees()" <<
				printCurrentCmd(command, options, informs) << endl;
			return nullptr;
		}

		try {
			auto searcher = search_factory.getSearch(informs[0].column);
			result = searchEmployees(*searcher, informs[0]);
		}
		catch (exception& e) {
			cout << "searchEmployees() is failed: " << e.what() <<
				printCurrentCmd(command, options, informs) << endl;
			return nullptr;
		}
		return result;
	}
	throw invalid_argument("invalid command");
}

string EmployeeManagement::printCurrentCmd(Command command, vector<Option> options, vector<Inform> informs) {
	string buffer;

	buffer += " CMD:";
	if (Command::ADD == command) { buffer += "ADD";  }
	else if (Command::DEL == command) { buffer += "DEL"; }
	else if (Command::SCH == command) { buffer += "SCH"; }
	else if (Command::MOD == command) { buffer += "MOD"; }
	else { buffer += "Unknown"; };

	buffer += ", op(";
	for (auto option : options) {
		buffer += string(to_string(static_cast<int>(option))) + ", ";
	}

	buffer += "), info(";
	for (auto inform : informs) {
		buffer += inform.column + "=";
		buffer += inform.value + ", ";
	}
	buffer += ")";

	return buffer;
}

void EmployeeManagement::addEmployee(unique_ptr<Employee> employee) {
	if (employee->employee_num == "") {
		throw invalid_argument("invalid employee information");
		return;
	}

	auto ret = employee_map.insert(make_pair(employee->employee_num, move(employee)));

	if (ret.second == false) {
		throw invalid_argument("fail to add employee");
	}
}

unique_ptr<vector<Employee>> EmployeeManagement::deleteEmployees(Search& searcher, const Inform info) {
	auto employees = make_unique<vector<Employee>>();
	auto search_result = searcher.search(employee_map, info);

	for (auto& employee : *search_result) {
		employees->emplace_back(employee);
		employee_map.erase(employee.employee_num);
	}
	return move(employees);
}

unique_ptr<vector<Employee>> EmployeeManagement::searchEmployees(Search& searcher, const Inform info) {
	auto employees = make_unique<vector<Employee>>();
	auto search_result = searcher.search(employee_map, info);

	for (auto& employee : *search_result) {
		employees->emplace_back(employee);
	}
	return move(employees);
}

unique_ptr<vector<Employee>> EmployeeManagement::modifyEmployees(Search& searcher, const Inform search_info, const Inform modify_info) {
	auto employees = make_unique<vector<Employee>>();
	auto search_result = searcher.search(employee_map, search_info);

	for (auto& employee : *search_result) {
		auto it = employee_map.find(employee.employee_num);
		if (it != employee_map.end()) {
			employees->emplace_back(employee);
			modifyEmployeeValue(*(it->second), modify_info);
		}
	}
	return move(employees);
}

void EmployeeManagement::modifyEmployeeValue(Employee& employee, const Inform info) {
	if(info.column == "employeeNum") throw invalid_argument("Can't modify employ number");
	else if (info.column == "name") {
		employee.name = info.value;
		employee.first_name = info.value.substr(0, info.value.find(" "));
		employee.last_name = info.value.substr(info.value.find(" ") + 1);
	}
	else if (info.column == "phoneNum") {
		employee.phone_num = info.value;
		size_t first_devider = info.value.find("-") + 1;
		size_t second_devider = info.value.find("-", first_devider);
		employee.mid_phone_num = info.value.substr(first_devider, second_devider - first_devider);
		employee.last_phone_num = info.value.substr(second_devider + 1);
	}
	else if (info.column == "birthday") {
		employee.birthday = info.value;
		employee.birthday_year = info.value.substr(0, 4);
		employee.birthday_month = info.value.substr(4, 2);
		employee.birthday_day = info.value.substr(6, 2);
	}
	else if (info.column == "cl") {
		employee.cl = info.value;
	}
	else if (info.column == "certi") {
		employee.certi = info.value;
	}
	else {
		throw invalid_argument("Invalid column string");
	}
}

const size_t EmployeeManagement::getEmployeeCount() const {
	return employee_map.size();
}

void EmployeeManagement::clearEmployee() {
	employee_map.clear();
}