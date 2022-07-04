#pragma once

#include <string>

#include "RasteriserInvalidDeviceTest.h"
#include "RasteriserInvalidContextTest.h"

class RasteriserInvalidTester
{
public:
	RasteriserInvalidTester();
	~RasteriserInvalidTester();

	std::string test();

private:
	std::string testDevice();
	std::string testContext();
};
