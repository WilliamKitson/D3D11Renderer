#pragma once

#include <string>

#include "default/GeometryDefaultTester.h"
#include "reload/GeometryReloadTester.h"
#include "strides/GeometryStridesTester.h"
#include "invalid/GeometryInvalidTester.h"

class GeometryTester
{
public:
	GeometryTester();
	~GeometryTester();

	std::string test();

private:
	std::string testDefault();
	std::string testReload();
	std::string testStrides();
	std::string testInvalid();
};
