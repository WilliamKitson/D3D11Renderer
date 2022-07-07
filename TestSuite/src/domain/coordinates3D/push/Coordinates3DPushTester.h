#pragma once

#include <string>

#include "Coordinates3DPushXTest.h"
#include "Coordinates3DPushYTest.h"
#include "Coordinates3DPushZTest.h"

class Coordinates3DPushTester
{
public:
	Coordinates3DPushTester();
	~Coordinates3DPushTester();

	std::string test();

private:
	std::string testX();
	std::string testY();
	std::string testZ();
};
