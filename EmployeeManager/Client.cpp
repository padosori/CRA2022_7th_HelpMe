#include "Client.h"

void Client::readInputFile(const string file_name) {
    ifstream readFile;
    readFile.open("../EmployeeManager/" + file_name);
    
    if (readFile.is_open()) {
        while (!readFile.eof()) {
            string str;
            getline(readFile, str);
            file_str_.emplace_back(str);
        }
        readFile.close();
    }
    else {
        throw invalid_argument("fail to open a file");
    }
}