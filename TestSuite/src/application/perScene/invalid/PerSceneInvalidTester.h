#pragma once

#include <string>
#include "PerSceneInvalidDeviceTest.h"

class PerSceneInvalidTester
{
public:
	PerSceneInvalidTester();
	~PerSceneInvalidTester();

	std::string test();

private:
	std::string testDevice();
};
