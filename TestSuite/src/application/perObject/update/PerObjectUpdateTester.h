#pragma once

#include <string>
#include "PerObjectUpdateTransformTest.h"

class PerObjectUpdateTester
{
public:
	PerObjectUpdateTester();
	~PerObjectUpdateTester();

	std::string test();

private:
	std::string testTransform();
};
