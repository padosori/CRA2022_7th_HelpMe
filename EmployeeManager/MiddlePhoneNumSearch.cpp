#include "MiddlePhoneNumSearch.h"

bool MiddlePhoneNumSearch::isCorrectColumn(string condition_column) {
	return(condition_column == "phoneNum_middle");
}

bool MiddlePhoneNumSearch::isMatched(Employee& employee, string condition_value) {
	return(employee.mid_phone_num == condition_value);
}
