#pragma once

#include <string>

#include "ShadersInvalidDeviceTest.h"
#include "ShadersInvalidContextTest.h"
#include "ShadersInvalidFilepathTest.h"

class ShadersInvalidTester
{
public:
	ShadersInvalidTester();
	~ShadersInvalidTester();

	std::string test();

private:
	std::string testDevice();
	std::string testContext();
	std::string testFilepath();
};
