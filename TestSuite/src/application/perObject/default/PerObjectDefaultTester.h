#pragma once

#include <string>

#include "PerObjectDefaultTransformTest.h"
#include "PerObjectDefaultColourTest.h"

class PerObjectDefaultTester
{
public:
	PerObjectDefaultTester();
	~PerObjectDefaultTester();

	std::string test();

private:
	std::string testTransform();
	std::string testColour();
};
