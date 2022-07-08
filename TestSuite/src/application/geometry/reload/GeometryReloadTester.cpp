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

	return output;
}

std::string GeometryReloadTester::testPositions()
{
	return GeometryReloadPositionsTest().test();
}
