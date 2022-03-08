#pragma once

#include "EmployeeListCmd.h"

class EmployeeListCmdFactory {
public:
	unique_ptr<EmployeeListCmd> getCmd(Command cmd);
};
