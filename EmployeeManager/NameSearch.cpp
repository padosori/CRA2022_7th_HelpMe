#include "NameSearch.h"

bool NameSearch::isCorrectColumn(string condition_column) {
	return(condition_column == "name");
}

bool NameSearch::isMatched(Employee& employee, string condition_value) {
	return(employee.name == condition_value);
}
