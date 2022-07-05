#pragma once

#include <string>
#include "default/PerSceneDefaultTester.h"

class PerSceneTester
{
public:
	PerSceneTester();
	~PerSceneTester();

	std::string test();

private:
	std::string testDefault();
};
