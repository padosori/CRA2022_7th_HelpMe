#include "pch.h"
#include "../EmployeeManager/EmployeeNumSearch.cpp"

//#include "TestEmployeeNumSearch.h"

class TestEmployeeNumSearch : public ::testing::Test {
protected:
	void SetUp() override {
		employee_num_search_ = std::make_shared<EmployeeNumSearch>();
		employee_map_.insert({ "2015123099", { "2015123099", "VXIHXOTH JHOP", "VXIHXOTH", "JHOP", "010 - 3112 - 2609", "3112", "2609", "19771211", "1977", "12", "11", "CL3", "ADV" } });
		employee_map_.insert({ "2017112609", { "2017112609","FB NTAWR","FB","NTAWR", "010 - 5645 - 6122","5645", "6122", "19861203","1986","12","03", "CL4", "PRO" } });
		employee_map_.insert({ "1988114052", { "1988114052","TTETHU HBO","TTETHU","HBO", "010 - 4581 - 2050","4581", "2050", "20080718","2008","07","18", "CL2", "ADV" } });
	}

	void TearDown() override {
	}

	std::shared_ptr<Search> employee_num_search_;
	std::map<std::string, Employee> employee_map_;

public:

};

TEST_F(TestEmployeeNumSearch, SearchItemTest) {
	Inform inform = { "employeeNum","2015123099" };
	auto result = employee_num_search_->search(employee_map_, inform);	
	EXPECT_EQ(1, result->size());
}

TEST_F(TestEmployeeNumSearch, TestWrongNum) {
	Inform inform = { "employeeNum","2015ss1299" };
	auto result = employee_num_search_->search(employee_map_, inform);
	EXPECT_EQ(0, result->size());
}

TEST_F(TestEmployeeNumSearch, TestWrongColumn) {
	Inform inform = { "cl","2015123099" };
	auto result = employee_num_search_->search(employee_map_, inform);
	EXPECT_EQ(0, result->size());
}