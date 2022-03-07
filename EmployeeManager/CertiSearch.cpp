#include "CertiSearch.h"

bool CertiSearch::isCorrectColumn(string condition_column) {
	return(condition_column == "certi");
}

bool CertiSearch::isMatched(Employee& employee, string condition_value) {
	return(employee.certi == condition_value);
}

