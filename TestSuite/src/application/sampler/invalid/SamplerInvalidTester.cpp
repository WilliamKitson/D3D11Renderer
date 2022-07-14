#include "SamplerInvalidTester.h"

SamplerInvalidTester::SamplerInvalidTester()
{
}

SamplerInvalidTester::~SamplerInvalidTester()
{
}

std::string SamplerInvalidTester::test()
{
	std::string output{ "" };

	output += testDevice();
	output += testContext();

	return output;
}

std::string SamplerInvalidTester::testDevice()
{
	return SamplerInvalidDeviceTest().test();
}

std::string SamplerInvalidTester::testContext()
{
	return SamplerInvalidContextTest().test();
}
