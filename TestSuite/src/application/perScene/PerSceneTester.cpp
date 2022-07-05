#include "PerSceneTester.h"

PerSceneTester::PerSceneTester()
{
}

PerSceneTester::~PerSceneTester()
{
}

std::string PerSceneTester::test()
{
	std::string output{ "" };

	output += testDefault();

	return output;
}

std::string PerSceneTester::testDefault()
{
	return PerSceneDefaultTester().test();
}
