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

	return output;
}

std::string PerObjectInvalidTester::testDevice()
{
	return PerObjectInvalidDeviceTest().test();
}
