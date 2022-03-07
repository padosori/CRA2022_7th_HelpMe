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
	else if (command == Command::DEL || command == Command::MOD || command == Command::SCH) {
		unique_ptr<vector<Employee>> result;

		if ((command == Command::DEL && informs.size() != 1) ||
			(command == Command::SCH && informs.size() != 1) ||
			(command == Command::MOD && informs.size() != 2)) {
			cout << "Invalid argument error" <<
				printCurrentCmd(command, options, informs) << endl;
			return nullptr;
		}

		try {
			auto searcher = search_factory.getSearch(informs[0].column);
			auto employee_list_cmd = cmd_factory.getCmd(command);
			result = employee_list_cmd->process(*this, *searcher, informs);
		}
		catch (exception& e) {
			cout << "processCmd() is failed: " << e.what() <<
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

	if (insert(make_pair(employee->employee_num, move(employee))) == false) {
		throw invalid_argument("fail to add employee");
	}
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