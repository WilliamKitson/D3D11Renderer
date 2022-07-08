#include "GeometryStridesTester.h"

GeometryStridesTester::GeometryStridesTester()
{
}

GeometryStridesTester::~GeometryStridesTester()
{
}

std::string GeometryStridesTester::test()
{
	std::string output{ "" };

	output += testPosition();

	return output;
}

std::string GeometryStridesTester::testPosition()
{
	return GeometryStridesPositionTest().test();
}
