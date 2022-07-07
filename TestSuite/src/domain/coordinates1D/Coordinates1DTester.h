#pragma once

#include <string>

#include "count/Coordinates1DCountTester.h"
#include "index/Coordinates1DIndexTester.h"

class Coordinates1DTester
{
public:
	Coordinates1DTester();
	~Coordinates1DTester();

	std::string test();

private:
	std::string testCount();
	std::string testIndex();
};
