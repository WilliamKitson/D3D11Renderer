#pragma once

#include <string>
#include "GeometryDefaultPositionsTest.h"

class GeometryDefaultTester
{
public:
	GeometryDefaultTester();
	~GeometryDefaultTester();

	std::string test();

private:
	std::string testPositions();
};
