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
	output += testNormal();

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

std::string GeometryStridesTester::testNormal()
{
	return GeometryStridesNormalTest().test();
}
