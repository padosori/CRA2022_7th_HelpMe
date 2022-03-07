#include "BirthdayMonthSearch.h"

bool BirthdayMonthSearch::isCorrectColumn(string condition_column) {
	return(condition_column == "birthday_month");
}

bool BirthdayMonthSearch::isMatched(Employee& employee, string condition_value) {
	return(employee.birthday_month == condition_value);
}
