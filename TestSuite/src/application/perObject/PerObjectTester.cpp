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
