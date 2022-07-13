#pragma once

#include <string>
#include "DirectionalReloadDirectionTest.h"

class DirectionalReloadTester
{
public:
	DirectionalReloadTester();
	~DirectionalReloadTester();

	std::string test();

private:
	std::string testDirection();
};
