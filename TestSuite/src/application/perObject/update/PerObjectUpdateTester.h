#pragma once

#include <string>

#include "PerObjectReloadTransformTest.h"
#include "PerObjectReloadColourTest.h"

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
