#include "LastPhoneNumSearch.h"

bool LastPhoneNumSearch::isCorrectColumn(string condition_column) {
	return(condition_column == "phoneNum_last");
}

bool LastPhoneNumSearch::isMatched(Employee& employee, string condition_value) {
	return(employee.last_phone_num == condition_value);
}
