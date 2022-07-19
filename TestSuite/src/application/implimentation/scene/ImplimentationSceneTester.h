#pragma once

#include <string>
#include "ImplimentationSceneDefaultTest.h"

class ImplimentationSceneTester
{
public:
	ImplimentationSceneTester();
	~ImplimentationSceneTester();

	std::string test();

private:
	std::string testDefault();
};
