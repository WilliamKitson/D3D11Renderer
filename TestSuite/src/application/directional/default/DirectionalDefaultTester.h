#pragma once

#include <string>

#include "DirectionalDefaultDirectionTest.h"
#include "DirectionalDefaultColourTest.h"

class DirectionalDefaultTester
{
public:
	DirectionalDefaultTester();
	~DirectionalDefaultTester();

	std::string test();

private:
	std::string testDirection();
	std::string testColour();
};
