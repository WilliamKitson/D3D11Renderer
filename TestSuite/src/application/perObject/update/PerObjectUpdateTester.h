#pragma once

#include <string>

#include "PerObjectUpdateTransformTest.h"
#include "PerObjectUpdateColourTest.h"

class PerObjectUpdateTester
{
public:
	PerObjectUpdateTester();
	~PerObjectUpdateTester();

	std::string test();

private:
	std::string testTransform();
	std::string testColour();
};
