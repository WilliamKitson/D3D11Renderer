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
	output += testInvalid();

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

std::string DirectionalTester::testInvalid()
{
	return DirectionalInvalidTester().test();
}
