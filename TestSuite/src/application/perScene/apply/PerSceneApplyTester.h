#pragma once

#include <string>

#include "PerSceneApplyWorldViewProjectionTest.h"
#include "PerSceneApplyAmbienceTest.h"

class PerSceneApplyTester
{
public:
	PerSceneApplyTester();
	~PerSceneApplyTester();

	std::string test();

private:
	std::string testWorldViewProjection();
	std::string testAmbience();
};
