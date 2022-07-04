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
	output += testUpdate();
	output += testApply();
	output += testInvalid();

	return output;
}

std::string PerObjectTester::testDefault()
{
	return PerObjectDefaultTester().test();
}

std::string PerObjectTester::testUpdate()
{
	return PerObjectUpdateTester().test();
}

std::string PerObjectTester::testApply()
{
	return PerObjectApplyTester().test();
}

std::string PerObjectTester::testInvalid()
{
	return PerObjectInvalidTester().test();
}
