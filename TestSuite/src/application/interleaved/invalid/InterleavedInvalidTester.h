#pragma once

#include <string>
#include "InterleavedInvalidDeviceTest.h"

class InterleavedInvalidTester
{
public:
	InterleavedInvalidTester();
	~InterleavedInvalidTester();

	std::string test();

private:
	std::string testDevice();
};
