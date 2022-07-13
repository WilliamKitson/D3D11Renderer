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
	output += testBind();

	return output;
}

std::string DirectionalInvalidTester::testInitialise()
{
	return DirectionalInvalidInitialiseTest().test();
}

std::string DirectionalInvalidTester::testBind()
{
	return DirectionalInvalidBindTest().test();
}
