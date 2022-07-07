#pragma once

#include <string>

#include "GeometryDefaultPositionsTest.h"
#include "GeometryDefaultTexcoordsTest.h"
#include "GeometryDefaultNormalsTest.h"

class GeometryDefaultTester
{
public:
	GeometryDefaultTester();
	~GeometryDefaultTester();

	std::string test();

private:
	std::string testPositions();
	std::string testTexcoords();
	std::string testNormals();
};
