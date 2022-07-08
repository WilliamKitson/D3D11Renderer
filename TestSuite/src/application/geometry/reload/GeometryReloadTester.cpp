#include "GeometryReloadTester.h"

GeometryReloadTester::GeometryReloadTester()
{
}

GeometryReloadTester::~GeometryReloadTester()
{
}

std::string GeometryReloadTester::test()
{
	std::string output{ "" };

	output += testPositions();
	output += testTexcoords();

	return output;
}

std::string GeometryReloadTester::testPositions()
{
	return GeometryReloadPositionsTest().test();
}

std::string GeometryReloadTester::testTexcoords()
{
	return GeometryReloadTexcoordsTest().test();
}
