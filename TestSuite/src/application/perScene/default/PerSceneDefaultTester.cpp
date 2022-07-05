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

	return output;
}

std::string PerSceneDefaultTester::testWorldViewProjection()
{
	return PerSceneDefaultWorldViewProjectionTest().test();
}
