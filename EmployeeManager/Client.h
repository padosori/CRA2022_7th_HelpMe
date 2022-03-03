#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Client {
public:
	void readInputFile(const string file_name);

private:
	vector<string> file_str_;
};