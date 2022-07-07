#pragma once

#include <string>

#include "Coordinates2DCountDefaultTest.h"
#include "Coordinates2DCountPushTest.h"
#include "Coordinates2DCountClearTest.h"

class Coordinates2DCountTester
{
public:
	Coordinates2DCountTester();
	~Coordinates2DCountTester();

	std::string test();

private:
	std::string testDefault();
	std::string testPush();
	std::string testClear();
};
