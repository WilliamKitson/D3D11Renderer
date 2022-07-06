#include "PerSceneApplyTester.h"

PerSceneApplyTester::PerSceneApplyTester()
{
}

PerSceneApplyTester::~PerSceneApplyTester()
{
}

std::string PerSceneApplyTester::test()
{
	std::string output{ "" };

	output += testWorldViewProjection();
	output += testAmbience();

	return output;
}

std::string PerSceneApplyTester::testWorldViewProjection()
{
	return PerSceneApplyWorldViewProjectionTest().test();
}

std::string PerSceneApplyTester::testAmbience()
{
	return PerSceneApplyAmbienceTest().test();
}
