#pragma once

#include <string>

#include "Coordinates3DCountDefaultTest.h"
#include "Coordinates3DCountPushTest.h"
#include "Coordinates3DCountClearTest.h"

class Coordinates3DCountTester
{
public:
	Coordinates3DCountTester();
	~Coordinates3DCountTester();

	std::string test();

private:
	std::string testDefault();
	std::string testPush();
	std::string testClear();
};
