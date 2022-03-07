#include "CmdFactory.h"

#include "DeleteEmployeeListCmd.h"
#include "SearchEmployeeListCmd.h"
#include "ModifyEmployeeListCmd.h"
#include <stdexcept>

using namespace std;

unique_ptr<EmployeeListCmd> EmployeeListCmdFactory::getCmd(Command cmd) {
	if (cmd == Command::DEL) { return std::make_unique <DeleteEmployeeListCmd> (); }
	else if (cmd == Command::SCH) { return std::make_unique <SearchEmployeeListCmd>(); }
	else if (cmd == Command::MOD) { return std::make_unique <ModifyEmployeeListCmd>(); }
	else {
		throw invalid_argument("invalid command in EmployeeListCmdFactory");
	}
}