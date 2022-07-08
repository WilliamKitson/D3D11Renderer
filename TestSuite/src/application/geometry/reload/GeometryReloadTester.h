#pragma once

#include <string>

#include "GeometryReloadPositionsTest.h"
#include "GeometryReloadTexcoordsTest.h"

class GeometryReloadTester
{
public:
	GeometryReloadTester();
	~GeometryReloadTester();

	std::string test();

private:
	std::string testPositions();
	std::string testTexcoords();
};
