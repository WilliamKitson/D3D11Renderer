#pragma once

#include <string>
#include "PerSceneDefaultWorldViewProjectionTest.h"

class PerSceneDefaultTester
{
public:
	PerSceneDefaultTester();
	~PerSceneDefaultTester();

	std::string test();

private:
	std::string testWorldViewProjection();
};
