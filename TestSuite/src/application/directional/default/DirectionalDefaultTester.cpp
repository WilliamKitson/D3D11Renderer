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

	return output;
}

std::string DirectionalDefaultTester::testDirection()
{
	return DirectionalDefaultDirectionTest().test();
}
