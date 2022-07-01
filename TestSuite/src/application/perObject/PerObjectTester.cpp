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

	return output;
}

std::string PerObjectTester::testDefault()
{
	return PerObjectDefaultTester().test();
}
