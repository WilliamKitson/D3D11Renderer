#pragma once

#include <string>

#include "SamplerInvalidDeviceTest.h"
#include "SamplerInvalidContextTest.h"

class SamplerInvalidTester
{
public:
	SamplerInvalidTester();
	~SamplerInvalidTester();

	std::string test();

private:
	std::string testDevice();
	std::string testContext();
};
