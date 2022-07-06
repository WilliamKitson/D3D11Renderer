#pragma once

#include <string>
#include "PerSceneApplyWorldViewProjectionTest.h"

class PerSceneApplyTester
{
public:
	PerSceneApplyTester();
	~PerSceneApplyTester();

	std::string test();

private:
	std::string testWorldViewProjection();
};
