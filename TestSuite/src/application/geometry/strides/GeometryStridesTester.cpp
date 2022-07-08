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
	output += testTexcoord();

	return output;
}

std::string GeometryStridesTester::testPosition()
{
	return GeometryStridesPositionTest().test();
}

std::string GeometryStridesTester::testTexcoord()
{
	return GeometryStridesTexcoordTest().test();
}
