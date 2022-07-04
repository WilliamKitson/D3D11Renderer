#pragma once

#include <string>

#include "PerObjectInvalidDeviceTest.h"
#include "PerObjectInvalidContextTest.h"

class PerObjectInvalidTester
{
public:
	PerObjectInvalidTester();
	~PerObjectInvalidTester();

	std::string test();

private:
	std::string testDevice();
	std::string testContext();
};
