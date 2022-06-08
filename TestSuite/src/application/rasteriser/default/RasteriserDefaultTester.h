#pragma once

#include <string>

#include "RasteriserDefaultModeTest.h"
#include "RasteriserDefaultCullingTest.h"

class RasteriserDefaultTester
{
public:
	RasteriserDefaultTester();
	~RasteriserDefaultTester();

	std::string test();

private:
	std::string testMode();
	std::string testCulling();
};
