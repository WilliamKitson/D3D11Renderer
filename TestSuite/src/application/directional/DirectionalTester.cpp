#include "DirectionalTester.h"

DirectionalTester::DirectionalTester()
{
}

DirectionalTester::~DirectionalTester()
{
}

std::string DirectionalTester::test()
{
	std::string output{ "" };

	output += testDefault();

	return output;
}

std::string DirectionalTester::testDefault()
{
	return DirectionalDefaultTester().test();
}
