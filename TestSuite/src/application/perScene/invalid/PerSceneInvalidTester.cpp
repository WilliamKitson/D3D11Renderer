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

	return output;
}

std::string PerSceneInvalidTester::testDevice()
{
	return PerSceneInvalidDeviceTest().test();
}
