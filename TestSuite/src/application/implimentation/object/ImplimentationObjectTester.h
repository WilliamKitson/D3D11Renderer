#pragma once

#include <string>

#include "ImplimentationObjectDefaultTest.h"
#include "ImplimentationObjectTransformTest.h"
#include "ImplimentationObjectColourTest.h"

class ImplimentationObjectTester
{
public:
	ImplimentationObjectTester();
	~ImplimentationObjectTester();

	std::string test();

private:
	std::string testDefault();
	std::string testTransform();
	std::string testColour();
};
