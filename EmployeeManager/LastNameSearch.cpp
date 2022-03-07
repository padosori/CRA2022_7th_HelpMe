#include "LastNameSearch.h"

bool LastNameSearch::isCorrectColumn(string condition_column) {
	return(condition_column == "name_last");
}

bool LastNameSearch::isMatched(Employee& employee, string condition_value) {
	return(employee.last_name == condition_value);
}
