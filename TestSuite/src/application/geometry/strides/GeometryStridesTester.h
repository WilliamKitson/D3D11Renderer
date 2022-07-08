#pragma once

#include <string>
#include "GeometryStridesPositionTest.h"

class GeometryStridesTester
{
public:
	GeometryStridesTester();
	~GeometryStridesTester();

	std::string test();

private:
	std::string testPosition();
};
