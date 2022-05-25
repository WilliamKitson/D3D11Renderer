#pragma once

#include <string>

#include "ResolutionParameterWidthTest.h"
#include "ResolutionParameterHeightTest.h"

class ResolutionParameterTester
{
public:
	ResolutionParameterTester();
	~ResolutionParameterTester();

	std::string test();

private:
	std::string testWidth();
	std::string testHeight();
};
