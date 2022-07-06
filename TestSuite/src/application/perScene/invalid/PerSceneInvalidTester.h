#pragma once

#include <string>

#include "PerSceneInvalidDeviceTest.h"
#include "PerSceneInvalidBindTest.h"
#include "PerSceneInvalidApplyTest.h"

class PerSceneInvalidTester
{
public:
	PerSceneInvalidTester();
	~PerSceneInvalidTester();

	std::string test();

private:
	std::string testDevice();
	std::string testBind();
	std::string testApply();
};
