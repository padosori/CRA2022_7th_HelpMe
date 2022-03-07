#pragma once
#include "Search.h"



class SearchFactory {
public:
	std::unique_ptr<Search> getSearch(std::string column);
	
};
