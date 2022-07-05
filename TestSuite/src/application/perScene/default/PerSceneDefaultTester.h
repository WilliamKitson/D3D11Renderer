#pragma once

#include <string>

#include "PerSceneDefaultWorldViewProjectionTest.h"
#include "PerSceneDefaultAmbienceTest.h"

class PerSceneDefaultTester
{
public:
	PerSceneDefaultTester();
	~PerSceneDefaultTester();

	std::string test();

private:
	std::string testWorldViewProjection();
	std::string testAmbience();
};
