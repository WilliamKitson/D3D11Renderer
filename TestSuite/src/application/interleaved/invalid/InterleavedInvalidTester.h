#pragma once

#include <string>

#include "InterleavedInvalidDeviceTest.h"
#include "InterleavedInvalidContextTest.h"

class InterleavedInvalidTester
{
public:
	InterleavedInvalidTester();
	~InterleavedInvalidTester();

	std::string test();

private:
	std::string testDevice();
	std::string testContext();
};
