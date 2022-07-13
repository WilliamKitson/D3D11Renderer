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

	return output;
}

std::string DirectionalReloadTester::testDirection()
{
	return DirectionalReloadDirectionTest().test();
}
