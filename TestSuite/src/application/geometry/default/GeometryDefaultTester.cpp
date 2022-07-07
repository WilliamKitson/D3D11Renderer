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

	return output;
}

std::string GeometryDefaultTester::testPositions()
{
	return GeometryDefaultPositionsTest().test();
}
