#include "PerSceneDefaultTester.h"

PerSceneDefaultTester::PerSceneDefaultTester()
{
}

PerSceneDefaultTester::~PerSceneDefaultTester()
{
}

std::string PerSceneDefaultTester::test()
{
	std::string output{ "" };

	output += testWorldViewProjection();
	output += testAmbience();

	return output;
}

std::string PerSceneDefaultTester::testWorldViewProjection()
{
	return PerSceneDefaultWorldViewProjectionTest().test();
}

std::string PerSceneDefaultTester::testAmbience()
{
	return PerSceneDefaultAmbienceTest().test();
}
