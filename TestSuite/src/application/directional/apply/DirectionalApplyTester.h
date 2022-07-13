#pragma once

#include <string>
#include "DirectionalApplyDirectionTest.h"

class DirectionalApplyTester
{
public:
	DirectionalApplyTester();
	~DirectionalApplyTester();

	std::string test();

private:
	std::string testDirection();
};
