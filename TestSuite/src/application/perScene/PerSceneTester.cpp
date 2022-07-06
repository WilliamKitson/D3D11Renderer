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
	output += testReload();
	output += testApply();

	return output;
}

std::string PerSceneTester::testDefault()
{
	return PerSceneDefaultTester().test();
}

std::string PerSceneTester::testReload()
{
	return PerSceneReloadTester().test();
}

std::string PerSceneTester::testApply()
{
	return PerSceneApplyTester().test();
}
