#include "PerObjectTester.h"

PerObjectTester::PerObjectTester()
{
}

PerObjectTester::~PerObjectTester()
{
}

std::string PerObjectTester::test()
{
	std::string output{ "" };

	output += testDefault();
	output += testReload();
	output += testApply();
	output += testInvalid();

	return output;
}

std::string PerObjectTester::testDefault()
{
	return PerObjectDefaultTester().test();
}

std::string PerObjectTester::testReload()
{
	return PerObjectReloadTester().test();
}

std::string PerObjectTester::testApply()
{
	return PerObjectApplyTester().test();
}

std::string PerObjectTester::testInvalid()
{
	return PerObjectInvalidTester().test();
}
