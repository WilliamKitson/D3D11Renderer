#pragma once

#include <string>

#include "PerObjectReloadColourTest.h"

class PerObjectReloadTester
{
public:
	PerObjectReloadTester();
	~PerObjectReloadTester();

	std::string test();

private:
	std::string testColour();
};
