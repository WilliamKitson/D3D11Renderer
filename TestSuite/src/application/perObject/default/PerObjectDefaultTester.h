#pragma once

#include <string>
#include "PerObjectDefaultTransformTest.h"

class PerObjectDefaultTester
{
public:
	PerObjectDefaultTester();
	~PerObjectDefaultTester();

	std::string test();

private:
	std::string testTransform();
};
