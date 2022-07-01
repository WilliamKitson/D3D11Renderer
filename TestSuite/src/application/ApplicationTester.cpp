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
	output += testRasteriser();
	output += testPerObject();

	return output;
}

std::string ApplicationTester::testSwapchain()
{
	return SwapchainTester(hInstance, nCmdShow).test();
}

std::string ApplicationTester::testRasteriser()
{
	return RasteriserTester().test();
}

std::string ApplicationTester::testPerObject()
{
	return PerObjectTester().test();
}
