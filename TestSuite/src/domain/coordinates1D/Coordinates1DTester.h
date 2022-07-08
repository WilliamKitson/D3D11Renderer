#pragma once

#include <string>

#include "count/Coordinates1DCountTester.h"
#include "index/Coordinates1DIndexTester.h"
#include "Coordinates1DPushTest.h"
#include "Coordinates1DEmptyTest.h"

class Coordinates1DTester
{
public:
	Coordinates1DTester();
	~Coordinates1DTester();

	std::string test();

private:
	std::string testCount();
	std::string testIndex();
	std::string testPush();
	std::string testEmpty();
};
