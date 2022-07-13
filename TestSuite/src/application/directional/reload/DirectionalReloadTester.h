#pragma once

#include <string>

#include "DirectionalReloadDirectionTest.h"
#include "DirectionalReloadColourTest.h"

class DirectionalReloadTester
{
public:
	DirectionalReloadTester();
	~DirectionalReloadTester();

	std::string test();

private:
	std::string testDirection();
	std::string testColour();
};
