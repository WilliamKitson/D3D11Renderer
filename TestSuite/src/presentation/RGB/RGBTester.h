#pragma once

#include <string>
#include "RGBRedTest.h"

class RGBTester
{
public:
	RGBTester();
	~RGBTester();

	std::string test();

private:
	std::string testRed();
};
