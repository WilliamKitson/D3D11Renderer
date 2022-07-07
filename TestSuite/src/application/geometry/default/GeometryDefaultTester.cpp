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
