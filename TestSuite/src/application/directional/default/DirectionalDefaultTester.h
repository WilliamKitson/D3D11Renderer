#pragma once

#include <string>
#include "DirectionalDefaultDirectionTest.h"

class DirectionalDefaultTester
{
public:
	DirectionalDefaultTester();
	~DirectionalDefaultTester();

	std::string test();

private:
	std::string testDirection();
};
