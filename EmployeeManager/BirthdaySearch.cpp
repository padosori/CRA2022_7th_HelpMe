#include "BirthdaySearch.h"

bool BirthdaySearch::isCorrectColumn(string condition_column) {
	return(condition_column == "birthday");
}

bool BirthdaySearch::isMatched(Employee& employee, string condition_value) {
	return(employee.birthday == condition_value);
}
