#pragma once

#include <string>
#include "RasteriserInvalidDeviceTest.h"

class RasteriserInvalidTester
{
public:
	RasteriserInvalidTester();
	~RasteriserInvalidTester();

	std::string test();

private:
	std::string testDevice();
};
