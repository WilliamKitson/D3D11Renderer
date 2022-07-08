#pragma once

#include <string>

#include "GeometryReloadPositionsTest.h"
#include "GeometryReloadTexcoordsTest.h"
#include "GeometryReloadNormalsTest.h"

class GeometryReloadTester
{
public:
	GeometryReloadTester();
	~GeometryReloadTester();

	std::string test();

private:
	std::string testPositions();
	std::string testTexcoords();
	std::string testNormals();
};
