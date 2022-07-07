#include "GeometryTester.h"

GeometryTester::GeometryTester()
{
}

GeometryTester::~GeometryTester()
{
}

std::string GeometryTester::test()
{
	std::string output{ "" };

	output += testDefault();

	return output;
}

std::string GeometryTester::testDefault()
{
	return GeometryDefaultTester().test();
}
