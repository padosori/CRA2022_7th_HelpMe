#include "BirthdayDaySearch.h"

bool BirthdayDaySearch::isCorrectColumn(string condition_column) {
	return(condition_column == "birthday_day");
}

bool BirthdayDaySearch::isMatched(Employee& employee, string condition_value) {
	return(employee.birthday_day == condition_value);
}
