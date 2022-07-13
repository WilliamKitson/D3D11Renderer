#include "DirectionalApplyTester.h"

DirectionalApplyTester::DirectionalApplyTester()
{
}

DirectionalApplyTester::~DirectionalApplyTester()
{
}

std::string DirectionalApplyTester::test()
{
	std::string output{ "" };

	output += testDirection();

	return output;
}

std::string DirectionalApplyTester::testDirection()
{
	return DirectionalApplyDirectionTest().test();
}
