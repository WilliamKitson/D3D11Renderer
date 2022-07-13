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
	output += testApply();

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

std::string DirectionalInvalidTester::testApply()
{
	return DirectionalInvalidApplyTest().test();
}
