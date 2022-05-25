#pragma once

#include <string>

#include "RGBARedTest.h"
#include "RGBAGreenTest.h"
#include "RGBABlueTest.h"

class RGBATester
{
public:
	RGBATester();
	~RGBATester();

	std::string test();

private:
	std::string testRed();
	std::string testGreen();
	std::string testBlue();
};
