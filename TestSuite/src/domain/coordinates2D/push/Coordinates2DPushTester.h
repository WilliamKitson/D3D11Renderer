#pragma once

#include <string>

#include "Coordinates2DPushXTest.h"
#include "Coordinates2DPushYTest.h"

class Coordinates2DPushTester
{
public:
	Coordinates2DPushTester();
	~Coordinates2DPushTester();

	std::string test();

private:
	std::string testX();
	std::string testY();
};
