#include "DirectionalInvalidTester.h"

DirectionalInvalidTester::DirectionalInvalidTester()
{
}

DirectionalInvalidTester::~DirectionalInvalidTester()
{
}

std::string DirectionalInvalidTester::test()
{
	std::string output{ "" };

	output += testInitialise();

	return output;
}

std::string DirectionalInvalidTester::testInitialise()
{
	return DirectionalInvalidInitialiseTest().test();
}
