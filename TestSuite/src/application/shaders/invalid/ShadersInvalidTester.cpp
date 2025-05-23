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
	output += testContext();
	output += testFilepath();

	return output;
}

std::string ShadersInvalidTester::testDevice()
{
	return ShadersInvalidDeviceTest().test();
}

std::string ShadersInvalidTester::testContext()
{
	return ShadersInvalidContextTest().test();
}

std::string ShadersInvalidTester::testFilepath()
{
	return ShadersInvalidFilepathTest().test();
}
