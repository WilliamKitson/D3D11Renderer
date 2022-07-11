#pragma once

#include <string>
#include "ShadersInvalidDeviceTest.h"

class ShadersInvalidTester
{
public:
	ShadersInvalidTester();
	~ShadersInvalidTester();

	std::string test();

private:
	std::string testDevice();
};
