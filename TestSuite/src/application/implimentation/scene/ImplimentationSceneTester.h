#pragma once

#include <string>

#include "ImplimentationSceneDefaultTest.h"
#include "ImplimentationSceneCameraTest.h"

class ImplimentationSceneTester
{
public:
	ImplimentationSceneTester();
	~ImplimentationSceneTester();

	std::string test();

private:
	std::string testDefault();
	std::string testCamera();
};
