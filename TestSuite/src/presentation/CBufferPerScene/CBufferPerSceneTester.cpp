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

	return output;
}

std::string CBufferPerSceneTester::testWorldViewProjection()
{
	return CBufferPerSceneWorldViewProjectionTest().test();
}
