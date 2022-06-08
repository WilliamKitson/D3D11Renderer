#pragma once

#include <string>

#include "RasteriserModeWireframeTest.h"
#include "RasteriserModeSolidTest.h"

class RasteriserModeTester
{
public:
	RasteriserModeTester();
	~RasteriserModeTester();

	std::string test();

private:
	std::string testWireframe();
	std::string testSolid();
};
