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
	output += testReload();

	return output;
}

std::string GeometryTester::testDefault()
{
	return GeometryDefaultTester().test();
}

std::string GeometryTester::testReload()
{
	return GeometryReloadTester().test();
}
