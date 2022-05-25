#pragma once

#include <string>
#include "RGBARedTest.h"

class RGBATester
{
public:
	RGBATester();
	~RGBATester();

	std::string test();

private:
	std::string testRed();
};
