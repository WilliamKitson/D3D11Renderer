#pragma once

#include <string>

#include "default/RasteriserDefaultTester.h"
#include "mode/RasteriserModeTester.h"

class RasteriserTester
{
public:
	RasteriserTester();
	~RasteriserTester();

	std::string test();

private:
	std::string testDefault();
	std::string testMode();
};
