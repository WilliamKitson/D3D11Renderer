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
	std::string failures{ "" };

	failures += testSwapchain();
	failures += testRasteriser();

	return failures;
}

std::string ApplicationTester::testSwapchain()
{
	return SwapchainTester(hInstance, nCmdShow).test();
}

std::string ApplicationTester::testRasteriser()
{
	return RasteriserTester().test();
}
