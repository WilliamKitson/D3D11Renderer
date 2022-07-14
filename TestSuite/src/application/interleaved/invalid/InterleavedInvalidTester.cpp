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

	return output;
}

std::string InterleavedInvalidTester::testDevice()
{
	return InterleavedInvalidDeviceTest().test();
}
