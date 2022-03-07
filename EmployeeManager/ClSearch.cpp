#include "ClSearch.h"

bool ClSearch::isCorrectColumn(string condition_column) {
	return(condition_column == "cl");
}

bool ClSearch::isMatched(Employee& employee, string condition_value) {
	return(employee.cl == condition_value);
}
