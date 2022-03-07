#pragma once
#include "Search.h"
#include "Employee.h"

class NameSearch : public Search {
protected:
	virtual bool isCorrectColumn(string condition_column) override;
	virtual bool isMatched(Employee& employee, string condition_value) override;
};
