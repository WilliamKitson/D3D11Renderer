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

	return output;
}

std::string PerSceneApplyTester::testWorldViewProjection()
{
	return PerSceneApplyWorldViewProjectionTest().test();
}
