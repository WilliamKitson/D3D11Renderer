#pragma once

#include <string>

#include "RGBRedTest.h"
#include "RGBGreenTest.h"
#include "RGBBlueTest.h"

class RGBTester
{
public:
	RGBTester();
	~RGBTester();

	std::string test();

private:
	std::string testRed();
	std::string testGreen();
	std::string testBlue();
};
