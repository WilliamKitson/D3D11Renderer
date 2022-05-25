#pragma once

#include <string>

#include "RGBRedTest.h"
#include "RGBGreenTest.h"

class RGBTester
{
public:
	RGBTester();
	~RGBTester();

	std::string test();

private:
	std::string testRed();
	std::string testGreen();
};
