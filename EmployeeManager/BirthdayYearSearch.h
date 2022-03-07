#pragma once
#include "Search.h"

class BirthdayYearSearch : public Search {
protected:
	virtual bool isCorrectColumn(string condition_column) override;
	virtual bool isMatched(Employee& employee, string condition_value) override;
};
