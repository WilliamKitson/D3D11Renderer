#pragma once

#include <string>

#include "DirectionalApplyDirectionTest.h"
#include "DirectionalApplyColourTest.h"

class DirectionalApplyTester
{
public:
	DirectionalApplyTester();
	~DirectionalApplyTester();

	std::string test();

private:
	std::string testDirection();
	std::string testColour();
};
