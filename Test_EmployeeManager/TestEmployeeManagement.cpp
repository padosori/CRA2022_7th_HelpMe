#include "pch.h"
#include "../EmployeeManager/Employee.h"
#include "../EmployeeManager/Search.h"
#include "../EmployeeManager/ClSearch.h"
#include "../EmployeeManager/EmployeeManagement.cpp"

class TestEmployeeManagement : public ::testing::Test {
protected:
	void SetUp() override {
		employees.push_back(Employee{ "11111111", "JAEMYUNG LEE", "JAEMYUNG", "LEE",
									  "010-1111-1111", "1111", "1111",
									  "19641222", "1964", "12", "22",
									  "CL1", "ADV" });
		employees.push_back(Employee{ "22222222", "SUKYEOL YOON", "SUKYEOL", "YOON",
									  "010-2222-2222", "2222", "2222",
									  "19601218", "1960", "12", "18",
									  "CL2", "PRO" });
		employees.push_back(Employee{ "33333333", "SANGJUNG SIM", "SANGJUNG", "SIM",
									  "010-3333-3333", "3333", "3333",
									  "19590404", "1959", "04", "04",
									  "CL3", "EX" });
		employees.push_back(Employee{ "44444444", "CHEOLSOO AHN", "CHEOLSOO", "AHN",
									  "010-4444-4444", "4444", "4444",
									  "19620226", "1962", "02", "26",
									  "CL4", "ADV" });
		employees.push_back(Employee{ "80808080", "JUNHO OH", "JUNHO", "OH",
									  "010-5555-5555", "5555", "5555",
									  "19750620", "1975", "06", "20",
									  "CL1", "PRO" });
		employees.push_back(Employee{ "90909090", "KYUNGYOUNG HUH", "KYUNGYOUNG", "HUH",
									  "010-6666-6666", "6666", "6666",
									  "19470713", "1947", "07", "13",
									  "CL2", "EX" });

		for (auto& employee : employees) {
			EXPECT_NO_THROW(employee_management.addEmployee(employee));
		}
	}

	void TearDown() override {
		employee_management.clearEmployee();
	}

	EmployeeManagement employee_management;
	vector<Employee> employees;
};

TEST_F(TestEmployeeManagement, ProcessCMD) {
	vector<Option> options;
	vector<Inform> informs;

	EXPECT_EQ(employee_management.getEmployeeCount(), 6);

	informs.push_back(Inform{ "employeeNum", "12341234" });
	informs.push_back(Inform{ "name", "GILDONG HONG" });
	informs.push_back(Inform{ "phoneNum", "010-1234-1234" });
	informs.push_back(Inform{ "birthday", "15000101" });
	informs.push_back(Inform{ "cl", "CL2" });
	informs.push_back(Inform{ "certi", "EX" });

	EXPECT_NO_THROW(employee_management.processCmd(Command::ADD, options, informs));
	EXPECT_EQ(employee_management.getEmployeeCount(), 7);

	informs.clear();
	informs.push_back(Inform{ "cl", "CL1" });
	auto employees = employee_management.processCmd(Command::SCH, options, informs);
	EXPECT_EQ((*employees).size(), 2);
	EXPECT_EQ((*employees)[0].cl, "CL1");
	EXPECT_EQ((*employees)[1].cl, "CL1");

	informs.clear();
	informs.push_back(Inform{ "cl", "CL1" });
	informs.push_back(Inform{ "cl", "CL3" });
	employees = employee_management.processCmd(Command::MOD, options, informs);
	EXPECT_EQ((*employees).size(), 2);
	EXPECT_EQ((*employees)[0].cl, "CL1");
	EXPECT_EQ((*employees)[1].cl, "CL1");

	informs.clear();
	informs.push_back(Inform{ "cl", "CL3" });
	employees = employee_management.processCmd(Command::DEL, options, informs);
	EXPECT_EQ((*employees).size(), 3);
	EXPECT_EQ((*employees)[0].cl, "CL3");
	EXPECT_EQ((*employees)[1].cl, "CL3");
	EXPECT_EQ((*employees)[2].cl, "CL3");
	EXPECT_EQ(employee_management.getEmployeeCount(), 4);
}

TEST_F(TestEmployeeManagement, ProcessCMDException) {
	vector<Option> options;
	vector<Inform> informs;

	informs.emplace_back(Inform{ "invalidColumn", "Test Name" });

	EXPECT_THROW(employee_management.processCmd(Command::ADD, options, informs), invalid_argument);
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

	EXPECT_NO_THROW(employee_management.addEmployee(employee));
	EXPECT_THROW(employee_management.addEmployee(employee), invalid_argument);

	employee = { "", "", "", "", "", "" };
	EXPECT_THROW(employee_management.addEmployee(employee), invalid_argument);
}

TEST_F(TestEmployeeManagement, Delete) {
	ClSearch searcher;
	unique_ptr<vector<Employee>> employees;

	Inform info = {"cl", "CL1"};
	EXPECT_NO_THROW(employees = employee_management.deleteEmployees(searcher, info));
	EXPECT_EQ(employees->size(), 2);
	EXPECT_EQ(employee_management.getEmployeeCount(), 4);

	info = { "cl", "CL2" };
	EXPECT_NO_THROW(employees = employee_management.deleteEmployees(searcher, info));
	EXPECT_EQ(employees->size(), 2);
	EXPECT_EQ(employee_management.getEmployeeCount(), 2);

	info = { "cl", "CL3" };
	EXPECT_NO_THROW(employees = employee_management.deleteEmployees(searcher, info));
	EXPECT_EQ(employees->size(), 1);
	EXPECT_EQ(employee_management.getEmployeeCount(), 1);

	info = { "cl", "CL4" };
	EXPECT_NO_THROW(employees = employee_management.deleteEmployees(searcher, info));
	EXPECT_EQ(employees->size(), 1);
	EXPECT_EQ(employee_management.getEmployeeCount(), 0);
}

TEST_F(TestEmployeeManagement, DeleteFail) {
	ClSearch searcher;

	EXPECT_EQ(employee_management.getEmployeeCount(), 6);
	Inform info = { "cl", "CL5" };
	EXPECT_THROW(employee_management.deleteEmployees(searcher, info), invalid_argument);
	EXPECT_EQ(employee_management.getEmployeeCount(), 6);
}


TEST_F(TestEmployeeManagement, Search) {
	ClSearch searcher;
	unique_ptr<vector<Employee>> employees;

	Inform info = { "cl", "CL1" };
	EXPECT_NO_THROW(employees = employee_management.searchEmployees(searcher, info));
	ASSERT_NE(employees, nullptr);
	ASSERT_EQ(employees->size(), 2);
	ASSERT_EQ((* employees)[0].cl, "CL1");
	ASSERT_EQ((*employees)[0].employee_num, "11111111");
	ASSERT_EQ((* employees)[1].cl, "CL1");
	ASSERT_EQ((*employees)[1].employee_num, "80808080");
}

TEST_F(TestEmployeeManagement, SearchFail) {
	ClSearch searcher;

	Inform info = { "cl", "CL5" };
	EXPECT_THROW(employee_management.searchEmployees(searcher, info), invalid_argument);
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


	Inform search_info = { "cl", "CL3" };
	EXPECT_NO_THROW(employees = employee_management.searchEmployees(searcher, search_info));
	ASSERT_NE(employees, nullptr);
	ASSERT_EQ(employees->size(), 1);

	search_info = { "cl", "CL1" };
	Inform modify_info = { "cl", "CL3" };
	EXPECT_NO_THROW(employees = employee_management.modifyEmployees(searcher, search_info, modify_info));
	ASSERT_NE(employees, nullptr);
	ASSERT_EQ(employees->size(), 2);

	search_info = { "cl", "CL3" };
	EXPECT_NO_THROW(employees = employee_management.searchEmployees(searcher, search_info));
	ASSERT_NE(employees, nullptr);
	ASSERT_EQ(employees->size(), 3);
}

TEST_F(TestEmployeeManagement, ModifyFail) {
	ClSearch searcher;

	Inform search_info{ "aaa", "aaa" };
	Inform modify_info{ "bbb", "bbb" };
	EXPECT_THROW(employee_management.modifyEmployees(searcher, search_info, modify_info), invalid_argument);
}
