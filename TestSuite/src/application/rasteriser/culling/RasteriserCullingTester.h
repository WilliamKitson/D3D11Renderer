#pragma once

#include <string>

#include "RasteriserCullingNoneTest.h"
#include "RasteriserCullingFrontTest.h"
#include "RasteriserCullingBackTest.h"

class RasteriserCullingTester
{
public:
	RasteriserCullingTester();
	~RasteriserCullingTester();

	std::string test();

private:
	std::string testNone();
	std::string testFront();
	std::string testBack();
};
