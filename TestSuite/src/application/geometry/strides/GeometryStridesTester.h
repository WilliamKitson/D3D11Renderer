#pragma once

#include <string>

#include "GeometryStridesPositionTest.h"
#include "GeometryStridesTexcoordTest.h"
#include "GeometryStridesNormalTest.h"

class GeometryStridesTester
{
public:
	GeometryStridesTester();
	~GeometryStridesTester();

	std::string test();

private:
	std::string testPosition();
	std::string testTexcoord();
	std::string testNormal();
};
