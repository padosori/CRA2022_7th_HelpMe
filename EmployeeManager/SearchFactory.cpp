#include "SearchFactory.h"
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

#include <stdexcept>

std::unique_ptr<Search> SearchFactory::getSearch(std::string column)
{
	if (column == "name") { return std::make_unique<NameSearch>(); }
	else if (column == "name_first") { return std::make_unique<FirstNameSearch>(); }
	else if (column == "name_last") { return std::make_unique<LastNameSearch>(); }
	else if (column == "phoneNum") { return std::make_unique<PhoneNumSearch>(); }
	else if (column == "phoneNum_middle") { return std::make_unique<MiddlePhoneNumSearch>(); }
	else if (column == "phoneNum_last") { return std::make_unique<LastPhoneNumSearch>(); }
	else if (column == "birthday") { return std::make_unique<BirthdaySearch>(); }
	else if (column == "birthday_year") { return std::make_unique<BirthdayYearSearch>(); }
	else if (column == "birthday_month") { return std::make_unique<BirthdayMonthSearch>(); }
	else if (column == "birthday_day") { return std::make_unique<BirthdayDaySearch>(); }
	else if (column == "employeeNum") { return std::make_unique<EmployeeNumSearch>(); }
	else if (column == "certi") { return std::make_unique<CertiSearch>(); }
	else if (column == "cl") { return std::make_unique<ClSearch>(); }
	else { 
		throw invalid_argument("invalid column");
	}
}
