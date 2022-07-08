#pragma once

#include <string>

#include "GeometryInvalidDeviceTest.h"
#include "GeometryInvalidContextTest.h"

class GeometryInvalidTester
{
public:
	GeometryInvalidTester();
	~GeometryInvalidTester();

	std::string test();

private:
	std::string testDevice();
	std::string testContext();
};
