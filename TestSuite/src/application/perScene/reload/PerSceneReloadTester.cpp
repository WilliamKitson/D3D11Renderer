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

	return output;
}

std::string PerSceneReloadTester::testWorldViewProjection()
{
	return PerSceneReloadWorldViewProjectionTest().test();
}
