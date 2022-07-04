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

	return output;
}

std::string RasteriserInvalidTester::testDevice()
{
	return RasteriserInvalidDeviceTest().test();
}
