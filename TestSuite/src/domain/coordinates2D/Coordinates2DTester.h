#pragma once

#include <string>

#include "count/Coordinates2DCountTester.h"
#include "empty/Coordinates2DEmptyTester.h"
#include "push/Coordinates2DPushTester.h"
#include "index/Coordinates2DIndexTester.h"

class Coordinates2DTester
{
public:
	Coordinates2DTester();
	~Coordinates2DTester();

	std::string test();

private:
	std::string testCount();
	std::string testEmpty();
	std::string testPush();
	std::string testIndex();
};
