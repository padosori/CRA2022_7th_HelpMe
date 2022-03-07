#include "PhoneNumSearch.h"

bool PhoneNumSearch::isCorrectColumn(string condition_column) {
	return(condition_column == "phoneNum");
}

bool PhoneNumSearch::isMatched(Employee& employee, string condition_value) {
	return(employee.phone_num == condition_value);
}
