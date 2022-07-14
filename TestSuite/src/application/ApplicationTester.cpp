#include "ApplicationTester.h"

ApplicationTester::ApplicationTester(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }
{
}

ApplicationTester::~ApplicationTester()
{
}

std::string ApplicationTester::test()
{
	std::string output{ "" };

	output += testSwapchain();
	output += testShaders();
	output += testInterleaved();
	output += testRasteriser();
	output += testSampler();
	output += testPerScene();
	output += testPerObject();

	return output;
}

std::string ApplicationTester::testSwapchain()
{
	return SwapchainTester(hInstance, nCmdShow).test();
}

std::string ApplicationTester::testShaders()
{
	return ShadersTester().test();
}

std::string ApplicationTester::testInterleaved()
{
	return InterleavedTester().test();
}

std::string ApplicationTester::testRasteriser()
{
	return RasteriserTester().test();
}

std::string ApplicationTester::testSampler()
{
	return SamplerTester().test();
}

std::string ApplicationTester::testPerScene()
{
	return PerSceneTester().test();
}

std::string ApplicationTester::testPerObject()
{
	return PerObjectTester().test();
}
