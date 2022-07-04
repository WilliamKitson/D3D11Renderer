#pragma once

#include <string>

#include "default/RasteriserDefaultTester.h"
#include "mode/RasteriserModeTester.h"
#include "culling/RasteriserCullingTester.h"
#include "invalid/RasteriserInvalidTester.h"

class RasteriserTester
{
public:
	RasteriserTester();
	~RasteriserTester();

	std::string test();

private:
	std::string testDefault();
	std::string testMode();
	std::string testCulling();
	std::string testInvalid();
};
