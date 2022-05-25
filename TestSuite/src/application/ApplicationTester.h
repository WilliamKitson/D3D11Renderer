#pragma once

#include <string>
#include "rasteriser/RasteriserTester.h"

class ApplicationTester
{
public:
	ApplicationTester();
	~ApplicationTester();

	std::string test();

private:
	std::string testRasteriser();
};
