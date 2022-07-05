#include "CBufferPerSceneTester.h"

CBufferPerSceneTester::CBufferPerSceneTester()
{
}

CBufferPerSceneTester::~CBufferPerSceneTester()
{
}

std::string CBufferPerSceneTester::test()
{
	std::string output{ "" };

	output += testWorldViewProjection();
	output += testAmbience();

	return output;
}

std::string CBufferPerSceneTester::testWorldViewProjection()
{
	return CBufferPerSceneWorldViewProjectionTest().test();
}

std::string CBufferPerSceneTester::testAmbience()
{
	return CBufferPerSceneAmbienceTest().test();
}
