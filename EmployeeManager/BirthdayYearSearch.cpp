#include "BirthdayYearSearch.h"

bool BirthdayYearSearch::isCorrectColumn(string condition_column) {
	return(condition_column == "birthday_year");
}

bool BirthdayYearSearch::isMatched(Employee& employee, string condition_value) {
	return(employee.birthday_year == condition_value);
}
