#pragma once

#include <string>
#include "PerObjectInvalidDeviceTest.h"

class PerObjectInvalidTester
{
public:
	PerObjectInvalidTester();
	~PerObjectInvalidTester();

	std::string test();

private:
	std::string testDevice();
};
