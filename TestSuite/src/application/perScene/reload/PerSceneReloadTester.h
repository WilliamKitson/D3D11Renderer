#pragma once

#include <string>

#include "PerSceneReloadWorldViewProjectionTest.h"
#include "PerSceneReloadAmbienceTest.h"

class PerSceneReloadTester
{
public:
	PerSceneReloadTester();
	~PerSceneReloadTester();

	std::string test();

private:
	std::string testWorldViewProjection();
	std::string testAmbience();
};
