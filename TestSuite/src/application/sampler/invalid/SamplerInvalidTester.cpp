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

	return output;
}

std::string SamplerInvalidTester::testDevice()
{
	return SamplerInvalidDeviceTest().test();
}
