#pragma once

#include <string>
#include "SamplerInvalidDeviceTest.h"

class SamplerInvalidTester
{
public:
	SamplerInvalidTester();
	~SamplerInvalidTester();

	std::string test();

private:
	std::string testDevice();
};
