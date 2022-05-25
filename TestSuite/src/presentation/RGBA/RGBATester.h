#pragma once

#include <string>

#include "RGBARedTest.h"
#include "RGBAGreenTest.h"
#include "RGBABlueTest.h"
#include "RGBAAlphaTest.h"

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
	std::string testAlpha();
};
