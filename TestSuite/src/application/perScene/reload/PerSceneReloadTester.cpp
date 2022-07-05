#include "PerSceneReloadTester.h"

PerSceneReloadTester::PerSceneReloadTester()
{
}

PerSceneReloadTester::~PerSceneReloadTester()
{
}

std::string PerSceneReloadTester::test()
{
	std::string output{ "" };

	output += testWorldViewProjection();
	output += testAmbience();

	return output;
}

std::string PerSceneReloadTester::testWorldViewProjection()
{
	return PerSceneReloadWorldViewProjectionTest().test();
}

std::string PerSceneReloadTester::testAmbience()
{
	return PerSceneReloadAmbienceTest().test();
}
