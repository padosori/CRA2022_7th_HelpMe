#include "FirstNameSearch.h"

bool FirstNameSearch::isCorrectColumn(string condition_column) {
	return(condition_column == "name_first");
}

bool FirstNameSearch::isMatched(Employee& employee, string condition_value) {
	return(employee.first_name == condition_value);
}
