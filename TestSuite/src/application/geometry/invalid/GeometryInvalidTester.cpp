#include "GeometryInvalidTester.h"

GeometryInvalidTester::GeometryInvalidTester()
{
}

GeometryInvalidTester::~GeometryInvalidTester()
{
}

std::string GeometryInvalidTester::test()
{
	std::string output{ "" };

	output += testDevice();
	output += testContext();

	return output;
}

std::string GeometryInvalidTester::testDevice()
{
	return GeometryInvalidDeviceTest().test();
}

std::string GeometryInvalidTester::testContext()
{
	return GeometryInvalidContextTest().test();
}
