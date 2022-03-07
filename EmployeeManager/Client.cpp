#include "Client.h"
#include "EmployeeManagement.h"
#include <fstream>

void Client::readInputFile(const string file_name) {
    ifstream input_file;

    input_file.open(file_name);
    if (!input_file.is_open()) { throw invalid_argument("fail to open a file"); }

    while (!input_file.eof()) {
        string str;
        getline(input_file, str);
        raw_lines.emplace_back(str);
    }
    input_file.close();
}

void Client::parseInputFile(void) {
    Parser parser;
    parsed_lines = parser.parse(raw_lines);
}

// TODO: refactoring, divide runAndWriteOutputFile() into two methods, if possible
void Client::runAndWriteOutputFile(const string file_name) {
    unique_ptr<EmployeeManagement> employee_management = make_unique<EmployeeManagement>();
    ofstream output_file(file_name);

    if (!output_file.is_open()) { throw invalid_argument("fail to open a file"); }

    for (auto parsed_line : *parsed_lines) {
        auto employees = move(employee_management->processCmd(
            parsed_line.command, parsed_line.options, parsed_line.informs));

        if (parsed_line.command == Command::ADD) { continue; }
        if (employees == nullptr) { continue; }

        output_file << parsed_line.command_str << ",";

        if (employees->size() == 0) { output_file << "NONE" << endl; continue; }
        if (parsed_line.options[0] != Option::PRINT) { output_file << employees->size() << endl; continue; }
        
        // TODO: Check if this counter works well
        size_t cnt = 1;
        for (auto employee : *employees) {
            if (cnt > 1) { output_file << parsed_line.command_str << ","; }
            output_file << employee.employee_num.substr(2, 8) << "," << employee.name << "," << employee.cl << ","
                << employee.phone_num << "," << employee.birthday << "," << employee.certi << endl;
            if (++cnt > MAX_PRINT_LINES) break;
        }
    }
    output_file.close();
}