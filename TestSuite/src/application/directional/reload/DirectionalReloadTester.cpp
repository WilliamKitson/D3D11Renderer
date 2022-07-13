#include "DirectionalReloadTester.h"

DirectionalReloadTester::DirectionalReloadTester()
{
}

DirectionalReloadTester::~DirectionalReloadTester()
{
}

std::string DirectionalReloadTester::test()
{
	std::string output{ "" };

	output += testDirection();
	output += testColour();

	return output;
}

std::string DirectionalReloadTester::testDirection()
{
	return DirectionalReloadDirectionTest().test();
}

std::string DirectionalReloadTester::testColour()
{
	return DirectionalReloadColourTest().test();
}
