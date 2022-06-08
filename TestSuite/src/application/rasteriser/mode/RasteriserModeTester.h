#pragma once

#include <string>
#include "RasteriserModeWireframeTest.h"

class RasteriserModeTester
{
public:
	RasteriserModeTester();
	~RasteriserModeTester();

	std::string test();

private:
	std::string testWireframe();
};
