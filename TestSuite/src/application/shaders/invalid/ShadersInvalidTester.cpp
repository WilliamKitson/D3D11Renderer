#include "ShadersInvalidTester.h"

ShadersInvalidTester::ShadersInvalidTester()
{
}

ShadersInvalidTester::~ShadersInvalidTester()
{
}

std::string ShadersInvalidTester::test()
{
	std::string output{ "" };

	output += testDevice();

	return output;
}

std::string ShadersInvalidTester::testDevice()
{
	return ShadersInvalidDeviceTest().test();
}
