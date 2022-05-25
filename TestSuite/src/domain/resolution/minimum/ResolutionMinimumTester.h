#pragma once

#include <string>

#include "ResolutionMinimumWidthTest.h"
#include "ResolutionMinimumHeightTest.h"

class ResolutionMinimumTester
{
public:
	ResolutionMinimumTester();
	~ResolutionMinimumTester();

	std::string test();

private:
	std::string testWidth();
	std::string testHeight();
};
