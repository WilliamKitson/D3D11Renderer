#pragma once

#include <string>
#include "default/RasteriserDefaultTester.h"

class RasteriserTester
{
public:
	RasteriserTester();
	~RasteriserTester();

	std::string test();

private:
	std::string testDefault();
};
