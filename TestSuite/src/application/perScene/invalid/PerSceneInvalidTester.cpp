#include "PerSceneInvalidTester.h"

PerSceneInvalidTester::PerSceneInvalidTester()
{
}

PerSceneInvalidTester::~PerSceneInvalidTester()
{
}

std::string PerSceneInvalidTester::test()
{
	std::string output{ "" };

	output += testDevice();
	output += testBind();

	return output;
}

std::string PerSceneInvalidTester::testDevice()
{
	return PerSceneInvalidDeviceTest().test();
}

std::string PerSceneInvalidTester::testBind()
{
	return PerSceneInvalidBindTest().test();
}
