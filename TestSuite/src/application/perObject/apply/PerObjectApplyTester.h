#pragma once

#include <string>
#include "PerObjectApplyTransformTest.h"

class PerObjectApplyTester
{
public:
	PerObjectApplyTester();
	~PerObjectApplyTester();

	std::string test();

private:
	std::string testTransform();
};
