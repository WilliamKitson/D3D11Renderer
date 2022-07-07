#pragma once

#include <string>

#include "Coordinates1DCountDefaultTest.h"
#include "Coordinates1DCountPushTest.h"

class Coordinates1DCountTester
{
public:
	Coordinates1DCountTester();
	~Coordinates1DCountTester();

	std::string test();

private:
	std::string testDefault();
	std::string testPush();
};
