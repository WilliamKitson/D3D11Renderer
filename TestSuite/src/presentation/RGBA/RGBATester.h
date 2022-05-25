#pragma once

#include <string>

#include "RGBARedTest.h"
#include "RGBAGreenTest.h"

class RGBATester
{
public:
	RGBATester();
	~RGBATester();

	std::string test();

private:
	std::string testRed();
	std::string testGreen();
};
