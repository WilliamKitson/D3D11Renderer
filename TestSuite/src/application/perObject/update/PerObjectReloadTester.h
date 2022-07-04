#pragma once

#include <string>

#include "PerObjectReloadTransformTest.h"
#include "PerObjectReloadColourTest.h"

class PerObjectReloadTester
{
public:
	PerObjectReloadTester();
	~PerObjectReloadTester();

	std::string test();

private:
	std::string testTransform();
	std::string testColour();
};
