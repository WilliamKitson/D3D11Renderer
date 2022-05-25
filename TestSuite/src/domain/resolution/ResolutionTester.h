#pragma once

#include <string>

#include "default/ResolutionDefaultTester.h"
#include "parameter/ResolutionParameterTester.h"
#include "minimum/ResolutionMinimumTester.h"

class ResolutionTester
{
public:
	ResolutionTester();
	~ResolutionTester();

	std::string test();

private:
	std::string testDefault();
	std::string testParameter();
	std::string testMinimum();
};
