#pragma once

#include <string>
#include "RasteriserDefaultModeTest.h"

class RasteriserDefaultTester
{
public:
	RasteriserDefaultTester();
	~RasteriserDefaultTester();

	std::string test();

private:
	std::string testMode();
};
