#include "pch.h"
#include "../EmployeeManager/sum.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCaseName, TestNameAdd) {
	EXPECT_EQ(33, sum(11,22));
}
