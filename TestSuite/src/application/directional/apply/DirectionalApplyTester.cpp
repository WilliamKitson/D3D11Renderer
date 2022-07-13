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
	output += testColour();

	return output;
}

std::string DirectionalApplyTester::testDirection()
{
	return DirectionalApplyDirectionTest().test();
}

std::string DirectionalApplyTester::testColour()
{
	return DirectionalApplyColourTest().test();
}
