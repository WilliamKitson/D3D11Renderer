#pragma once

#include <string>
#include "default/DirectionalDefaultTester.h"

class DirectionalTester
{
public:
	DirectionalTester();
	~DirectionalTester();

	std::string test();

private:
	std::string testDefault();
};
