#pragma once

#include <string>

#include "PerObjectApplyTransformTest.h"
#include "PerObjectApplyColourTest.h"

class PerObjectApplyTester
{
public:
	PerObjectApplyTester();
	~PerObjectApplyTester();

	std::string test();

private:
	std::string testTransform();
	std::string testColour();
};
