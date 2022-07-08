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

	return output;
}

std::string GeometryInvalidTester::testDevice()
{
	return GeometryInvalidDeviceTest().test();
}
