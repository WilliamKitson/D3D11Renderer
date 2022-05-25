#pragma once

#include <string>

#include "ResolutionDefaultWidthTest.h"
#include "ResolutionDefaultHeightTest.h"

class ResolutionDefaultTester
{
public:
	ResolutionDefaultTester();
	~ResolutionDefaultTester();

	std::string test();

private:
	std::string testWidth();
	std::string testHeight();
};
