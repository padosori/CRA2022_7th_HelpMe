#include "pch.h"
#include "../EmployeeManager/Employee.h"
#include "../EmployeeManager/Search.h"
#include "../EmployeeManager/ClSearch.h"
#include "../EmployeeManager/EmployeeListCmd.h"
#include "../EmployeeManager/DeleteEmployeeListCmd.cpp"
#include "../EmployeeManager/SearchEmployeeListCmd.cpp"
#include "../EmployeeManager/ModifyEmployeeListCmd.cpp"
#include "../EmployeeManager/CmdFactory.cpp"
#include "../EmployeeManager/EmployeeManagement.cpp"

class TestEmployeeManagement : public ::testing::Test {
protected:
	void SetUp() override {
		employees.emplace_back(Employee{ "11111111", "JAEMYUNG LEE", "JAEMYUNG", "LEE",
									  "010-1111-1111", "1111", "1111",
									  "19641222", "1964", "12", "22",
									  "CL1", "ADV" });
		employees.emplace_back(Employee{ "22222222", "SUKYEOL YOON", "SUKYEOL", "YOON",
									  "010-2222-2222", "2222", "2222",
									  "19601218", "1960", "12", "18",
									  "CL2", "PRO" });
		employees.emplace_back(Employee{ "33333333", "SANGJUNG SIM", "SANGJUNG", "SIM",
									  "010-3333-3333", "3333", "3333",
									  "19590404", "1959", "04", "04",
									  "CL3", "EX" });
		employees.emplace_back(Employee{ "44444444", "CHEOLSOO AHN", "CHEOLSOO", "AHN",
									  "010-4444-4444", "4444", "4444",
									  "19620226", "1962", "02", "26",
									  "CL4", "ADV" });
		employees.emplace_back(Employee{ "80808080", "JUNHO OH", "JUNHO", "OH",
									  "010-5555-5555", "5555", "5555",
									  "19750620", "1975", "06", "20",
									  "CL1", "PRO" });
		employees.emplace_back(Employee{ "90909090", "KYUNGYOUNG HUH", "KYUNGYOUNG", "HUH",
									  "010-6666-6666", "6666", "6666",
									  "19470713", "1947", "07", "13",
									  "CL2", "EX" });

		for (auto& employee : employees) {
			EXPECT_NO_THROW(employee_management.addEmployee(move(make_unique<Employee>(employee))));
		}
	}

	void TearDown() override {
		employee_management.clearEmployee();
	}

	EmployeeManagement employee_management;
	vector<Employee> employees;
	EmployeeListCmdFactory cmd_factory;
};

TEST_F(TestEmployeeManagement, ProcessCMD) {
	vector<Option> options;
	vector<Inform> informs;

	EXPECT_EQ(employee_management.getEmployeeCount(), 6);

	informs.emplace_back(Inform{ "employeeNum", "12341234" });
	informs.emplace_back(Inform{ "name", "GILDONG HONG" });
	informs.emplace_back(Inform{ "phoneNum", "010-1234-1234" });
	informs.emplace_back(Inform{ "birthday", "15000101" });
	informs.emplace_back(Inform{ "cl", "CL2" });
	informs.emplace_back(Inform{ "certi", "EX" });

	EXPECT_NO_THROW(employee_management.processCmd(Command::ADD, options, informs));
	EXPECT_EQ(employee_management.getEmployeeCount(), 7);

	informs.clear();
	informs.emplace_back(Inform{ "cl", "CL1" });
	auto employees = employee_management.processCmd(Command::SCH, options, informs);
	EXPECT_EQ((*employees).size(), 2);
	EXPECT_EQ((*employees)[0].cl, "CL1");
	EXPECT_EQ((*employees)[1].cl, "CL1");

	informs.clear();
	informs.emplace_back(Inform{ "cl", "CL1" });
	informs.emplace_back(Inform{ "cl", "CL3" });
	employees = employee_management.processCmd(Command::MOD, options, informs);
	EXPECT_EQ((*employees).size(), 2);
	EXPECT_EQ((*employees)[0].cl, "CL1");
	EXPECT_EQ((*employees)[1].cl, "CL1");

	informs.clear();
	informs.emplace_back(Inform{ "cl", "CL3" });
	employees = employee_management.processCmd(Command::DEL, options, informs);
	EXPECT_EQ((*employees).size(), 3);
	EXPECT_EQ((*employees)[0].cl, "CL3");
	EXPECT_EQ((*employees)[1].cl, "CL3");
	EXPECT_EQ((*employees)[2].cl, "CL3");
	EXPECT_EQ(employee_management.getEmployeeCount(), 4);
}

TEST_F(TestEmployeeManagement, ProcessCmdEmployeeSearchFactory) {
	vector<Option> options;
	vector<Inform> informs;

	EXPECT_EQ(employee_management.getEmployeeCount(), 6);

	informs.clear();
	informs.push_back(Inform{ "employeeNum", "11111111" });
	auto employees = employee_management.processCmd(Command::SCH, options, informs);
	EXPECT_EQ((*employees).size(), 1);
	EXPECT_EQ((*employees)[0].employee_num, "11111111");

	informs.clear();
	informs.push_back(Inform{ "name", "KYUNGYOUNG HUH" });
	employees = employee_management.processCmd(Command::SCH, options, informs);
	EXPECT_EQ((*employees).size(), 1);
	EXPECT_EQ((*employees)[0].name, "KYUNGYOUNG HUH");

	informs.clear();
	informs.push_back(Inform{ "phoneNum", "010-3333-3333" });
	employees = employee_management.processCmd(Command::SCH, options, informs);
	EXPECT_EQ((*employees).size(), 1);
	EXPECT_EQ((*employees)[0].phone_num, "010-3333-3333");

	informs.clear();
	informs.push_back(Inform{ "birthday", "19601218" });
	employees = employee_management.processCmd(Command::SCH, options, informs);
	EXPECT_EQ((*employees).size(), 1);
	EXPECT_EQ((*employees)[0].birthday, "19601218");

	informs.clear();
	informs.push_back(Inform{ "cl", "CL2" });
	employees = employee_management.processCmd(Command::SCH, options, informs);
	EXPECT_EQ((*employees).size(), 2);
	EXPECT_EQ((*employees)[0].cl, "CL2");
	EXPECT_EQ((*employees)[1].cl, "CL2");

	informs.clear();
	informs.push_back(Inform{ "certi", "EX" });
	employees = employee_management.processCmd(Command::SCH, options, informs);
	EXPECT_EQ((*employees).size(), 2);
	EXPECT_EQ((*employees)[0].certi, "EX");
	EXPECT_EQ((*employees)[1].certi, "EX");

	EXPECT_EQ(employee_management.getEmployeeCount(), 6);
}

TEST_F(TestEmployeeManagement, ProcessCMDException) {
	vector<Option> options;
	vector<Inform> informs;

	informs.emplace_back(Inform{ "invalidColumn", "Test Name" });

	EXPECT_THROW(employee_management.processCmd(Command::ADD, options, informs), invalid_argument);
}

TEST_F(TestEmployeeManagement, printCurrentCmd) {
	vector<Option> options;
	vector<Inform> informs;

	EXPECT_EQ(employee_management.getEmployeeCount(), 6);

	informs.emplace_back(Inform{ "employeeNum", "12341234" });
	informs.emplace_back(Inform{ "name", "GILDONG HONG" });
	informs.emplace_back(Inform{ "phoneNum", "010-1234-1234" });
	informs.emplace_back(Inform{ "birthday", "15000101" });
	informs.emplace_back(Inform{ "cl", "CL2" });
	informs.emplace_back(Inform{ "certi", "EX" });

	string result = employee_management.printCurrentCmd(Command::ADD, options, informs);
	EXPECT_EQ(result, " CMD:ADD, op(), info(employeeNum=12341234, name=GILDONG HONG, phoneNum=010-1234-1234, \
birthday=15000101, cl=CL2, certi=EX, )");
}

TEST_F(TestEmployeeManagement, GetEmployeeCount) {
	ASSERT_EQ(employee_management.getEmployeeCount(), 6);
}

TEST_F(TestEmployeeManagement, ClearEmployee) {
	EXPECT_EQ(employee_management.getEmployeeCount(), 6);
	employee_management.clearEmployee();
	EXPECT_EQ(employee_management.getEmployeeCount(), 0);
}


TEST_F(TestEmployeeManagement, Add) {
	ASSERT_EQ(employee_management.getEmployeeCount(), 6);
}

TEST_F(TestEmployeeManagement, AddFail) {
	Employee employee{ "12341234", "GILDONG HONG", "GILDONG", "HONG",
					   "010-1234-1234", "1234", "66612346",
					   "15000101", "1500", "01", "01",
					   "CL2", "EX" };
	
	EXPECT_NO_THROW(employee_management.addEmployee(move(make_unique<Employee>(employee))));
	EXPECT_THROW(employee_management.addEmployee(move(make_unique<Employee>(employee))), invalid_argument);

	employee = { "", "", "", "", "", "" };
	EXPECT_THROW(employee_management.addEmployee(move(make_unique<Employee>(employee))), invalid_argument);
}

TEST_F(TestEmployeeManagement, Delete) {
	ClSearch searcher;
	unique_ptr<vector<Employee>> employees;

	vector<Inform> informs;
	informs.push_back({ "cl", "CL1" });

	auto employee_list_cmd = cmd_factory.getCmd(Command::DEL);
	EXPECT_NO_THROW(employees = employee_list_cmd->process(employee_management, searcher, informs));
	EXPECT_EQ(employees->size(), 2);
	EXPECT_EQ(employee_management.getEmployeeCount(), 4);

	informs.clear();
	informs.push_back({ "cl", "CL2" });
	EXPECT_NO_THROW(employees = employee_list_cmd->process(employee_management, searcher, informs));
	EXPECT_EQ(employees->size(), 2);
	EXPECT_EQ(employee_management.getEmployeeCount(), 2);

	informs.clear();
	informs.push_back({ "cl", "CL3" });
	EXPECT_NO_THROW(employees = employee_list_cmd->process(employee_management, searcher, informs));
	EXPECT_EQ(employees->size(), 1);
	EXPECT_EQ(employee_management.getEmployeeCount(), 1);

	informs.clear();
	informs.push_back({ "cl", "CL4" });
	EXPECT_NO_THROW(employees = employee_list_cmd->process(employee_management, searcher, informs));
	EXPECT_EQ(employees->size(), 1);
	EXPECT_EQ(employee_management.getEmployeeCount(), 0);
}

TEST_F(TestEmployeeManagement, DeleteFail) {
	ClSearch searcher;

	EXPECT_EQ(employee_management.getEmployeeCount(), 6);

	vector<Inform> informs;
	informs.push_back({ "cl", "CL5" });
	auto employee_list_cmd = cmd_factory.getCmd(Command::DEL);
	EXPECT_EQ(employee_list_cmd->process(employee_management, searcher, informs)->size(), 0);
	EXPECT_EQ(employee_management.getEmployeeCount(), 6);
}


TEST_F(TestEmployeeManagement, Search) {
	ClSearch searcher;
	unique_ptr<vector<Employee>> employees;

	vector<Inform> informs;
	informs.push_back({ "cl", "CL1" });
	auto employee_list_cmd = cmd_factory.getCmd(Command::SCH);
	EXPECT_NO_THROW(employees = employee_list_cmd->process(employee_management, searcher, informs));
	ASSERT_NE(employees, nullptr);
	ASSERT_EQ(employees->size(), 2);
	ASSERT_EQ((* employees)[0].cl, "CL1");
	ASSERT_EQ((*employees)[0].employee_num, "11111111");
	ASSERT_EQ((* employees)[1].cl, "CL1");
	ASSERT_EQ((*employees)[1].employee_num, "80808080");
}

TEST_F(TestEmployeeManagement, SearchFail) {
	ClSearch searcher;

	vector<Inform> informs;
	informs.push_back({ "cl", "CL5" });
	auto employee_list_cmd = cmd_factory.getCmd(Command::SCH);
	EXPECT_EQ(employee_list_cmd->process(employee_management, searcher, informs)->size(), 0);
}

TEST_F(TestEmployeeManagement, modifyEmployeeValue) {
	Employee employee{ "00112233", "Gildong Hong", "Gildong", "Hong",
		"010-1234-5678", "1234", "5678",
		"20000102", "2000", "01", "02",
		"CL1", "PRO" };

	Inform modify_info{ "name", "HongGil Dong" };
	EXPECT_NO_THROW(employee_management.modifyEmployeeValue(employee, modify_info));
	EXPECT_EQ(employee.name, "HongGil Dong");
	EXPECT_EQ(employee.first_name, "HongGil");
	EXPECT_EQ(employee.last_name, "Dong");

	modify_info = { "phoneNum", "010-8888-9999" };
	EXPECT_NO_THROW(employee_management.modifyEmployeeValue(employee, modify_info));
	EXPECT_EQ(employee.phone_num, "010-8888-9999");
	EXPECT_EQ(employee.mid_phone_num, "8888");
	EXPECT_EQ(employee.last_phone_num, "9999");

	modify_info = { "birthday", "19990910" };
	EXPECT_NO_THROW(employee_management.modifyEmployeeValue(employee, modify_info));
	EXPECT_EQ(employee.birthday, "19990910");
	EXPECT_EQ(employee.birthday_year, "1999");
	EXPECT_EQ(employee.birthday_month, "09");
	EXPECT_EQ(employee.birthday_day, "10");

	modify_info = { "cl", "CL4" };
	EXPECT_NO_THROW(employee_management.modifyEmployeeValue(employee, modify_info));
	EXPECT_EQ(employee.cl, "CL4");

	modify_info = { "certi", "EX" };
	EXPECT_NO_THROW(employee_management.modifyEmployeeValue(employee, modify_info));
	EXPECT_EQ(employee.certi, "EX");

	modify_info = { "aaaa", "aaaa" };
	EXPECT_THROW(employee_management.modifyEmployeeValue(employee, modify_info), invalid_argument);
}


TEST_F(TestEmployeeManagement, Modify) {
	ClSearch searcher;
	unique_ptr<vector<Employee>> employees;

	vector<Inform> informs;
	informs.push_back({ "cl", "CL3" });
	auto employee_list_cmd = cmd_factory.getCmd(Command::SCH);
	EXPECT_NO_THROW(employees = employee_list_cmd->process(employee_management, searcher, informs));
	ASSERT_NE(employees, nullptr);
	ASSERT_EQ(employees->size(), 1);

	informs.clear();
	informs.push_back({ "cl", "CL1" });
	informs.push_back({ "cl", "CL3" });
	employee_list_cmd = cmd_factory.getCmd(Command::MOD);
	EXPECT_NO_THROW(employees = employee_list_cmd->process(employee_management, searcher, informs));
	ASSERT_NE(employees, nullptr);
	ASSERT_EQ(employees->size(), 2);

	informs.clear();
	informs.push_back({ "cl", "CL3" });
	employee_list_cmd = cmd_factory.getCmd(Command::SCH);
	EXPECT_NO_THROW(employees = employee_list_cmd->process(employee_management, searcher, informs));
	ASSERT_NE(employees, nullptr);
	ASSERT_EQ(employees->size(), 3);
}

TEST_F(TestEmployeeManagement, ModifyFail) {
	ClSearch searcher;

	vector<Inform> informs;
	informs.clear();
	informs.push_back({ "aaa", "aaa" });
	informs.push_back({ "aaa", "aaa" });
	auto employee_list_cmd = cmd_factory.getCmd(Command::MOD);
	EXPECT_EQ(employee_list_cmd->process(employee_management, searcher, informs)->size(), 0);
}