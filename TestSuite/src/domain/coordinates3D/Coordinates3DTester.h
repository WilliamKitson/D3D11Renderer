#pragma once

#include <string>

#include "count/Coordinates3DCountTester.h"
#include "empty/Coordinates3DEmptyTester.h"
#include "push/Coordinates3DPushTester.h"
#include "index/Coordinates3DIndexTester.h"

class Coordinates3DTester
{
public:
	Coordinates3DTester();
	~Coordinates3DTester();

	std::string test();

private:
	std::string testCount();
	std::string testEmpty();
	std::string testPush();
	std::string testIndex();
};
