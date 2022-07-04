#include "PerObjectInvalidTester.h"

PerObjectInvalidTester::PerObjectInvalidTester()
{
}

PerObjectInvalidTester::~PerObjectInvalidTester()
{
}

std::string PerObjectInvalidTester::test()
{
	std::string output{ "" };

	output += testDevice();
	output += testContext();

	return output;
}

std::string PerObjectInvalidTester::testDevice()
{
	return PerObjectInvalidDeviceTest().test();
}

std::string PerObjectInvalidTester::testContext()
{
	return PerObjectInvalidContextTest().test();
}
