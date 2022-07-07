#include "GeometryDefaultTester.h"

GeometryDefaultTester::GeometryDefaultTester()
{
}

GeometryDefaultTester::~GeometryDefaultTester()
{
}

std::string GeometryDefaultTester::test()
{
	std::string output{ "" };

	output += testPositions();
	output += testTexcoords();
	output += testNormals();

	return output;
}

std::string GeometryDefaultTester::testPositions()
{
	return GeometryDefaultPositionsTest().test();
}

std::string GeometryDefaultTester::testTexcoords()
{
	return GeometryDefaultTexcoordsTest().test();
}

std::string GeometryDefaultTester::testNormals()
{
	return GeometryDefaultNormalsTest().test();
}
