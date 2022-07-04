#include "RasteriserInvalidTester.h"

RasteriserInvalidTester::RasteriserInvalidTester()
{
}

RasteriserInvalidTester::~RasteriserInvalidTester()
{
}

std::string RasteriserInvalidTester::test()
{
	std::string output{ "" };

	output += testDevice();
	output += testContext();

	return output;
}

std::string RasteriserInvalidTester::testDevice()
{
	return RasteriserInvalidDeviceTest().test();
}

std::string RasteriserInvalidTester::testContext()
{
	return RasteriserInvalidContextTest().test();
}
