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
	output += testReload();
	output += testApply();

	return output;
}

std::string DirectionalTester::testDefault()
{
	return DirectionalDefaultTester().test();
}

std::string DirectionalTester::testReload()
{
	return DirectionalReloadTester().test();
}

std::string DirectionalTester::testApply()
{
	return DirectionalApplyTester().test();
}
