#pragma once

#include <string>
#include "GeometryReloadPositionsTest.h"

class GeometryReloadTester
{
public:
	GeometryReloadTester();
	~GeometryReloadTester();

	std::string test();

private:
	std::string testPositions();
};
