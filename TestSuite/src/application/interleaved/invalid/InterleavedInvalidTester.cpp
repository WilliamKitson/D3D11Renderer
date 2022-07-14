#include "InterleavedInvalidTester.h"

InterleavedInvalidTester::InterleavedInvalidTester()
{
}

InterleavedInvalidTester::~InterleavedInvalidTester()
{
}

std::string InterleavedInvalidTester::test()
{
	std::string output{ "" };

	output += testDevice();
	output += testContext();

	return output;
}

std::string InterleavedInvalidTester::testDevice()
{
	return InterleavedInvalidDeviceTest().test();
}

std::string InterleavedInvalidTester::testContext()
{
	return InterleavedInvalidContextTest().test();
}
