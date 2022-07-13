#include "DirectionalDefaultTester.h"

DirectionalDefaultTester::DirectionalDefaultTester()
{
}

DirectionalDefaultTester::~DirectionalDefaultTester()
{
}

std::string DirectionalDefaultTester::test()
{
	std::string output{ "" };

	output += testDirection();
	output += testColour();

	return output;
}

std::string DirectionalDefaultTester::testDirection()
{
	return DirectionalDefaultDirectionTest().test();
}

std::string DirectionalDefaultTester::testColour()
{
	return DirectionalDefaultColourTest().test();
}
