#pragma once
#include "Search.h"

#include "NameSearch.h"
#include "FirstNameSearch.h"
#include "LastNameSearch.h"

#include "PhoneNumSearch.h"
#include "MiddlePhoneNumSearch.h"
#include "LastPhoneNumSearch.h"

#include "BirthdaySearch.h"
#include "BirthdayYearSearch.h"
#include "BirthdayMonthSearch.h"
#include "BirthdayDaySearch.h"

#include "EmployeeNumSearch.h"
#include "CertiSearch.h"
#include "ClSearch.h"
class SearchFactory {
public:
	std::unique_ptr<Search> getSearch(std::string column);
	
};
