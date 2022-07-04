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
	output += testBind();

	return output;
}

std::string PerObjectInvalidTester::testDevice()
{
	return PerObjectInvalidDeviceTest().test();
}

std::string PerObjectInvalidTester::testBind()
{
	return PerObjectInvalidBindTest().test();
}
