#include "SwapchainResolutionTester.h"

SwapchainResolutionTester::SwapchainResolutionTester(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }
{
}

SwapchainResolutionTester::~SwapchainResolutionTester()
{
}

std::string SwapchainResolutionTester::test()
{
	std::string output{ "" };

	output += testView();
	output += testDepth();
	output += testViewport();

	return output;
}

std::string SwapchainResolutionTester::testView()
{
	return SwapchainResolutionViewTest(hInstance, nCmdShow).test();
}

std::string SwapchainResolutionTester::testDepth()
{
	return SwapchainResolutionDepthTest(hInstance, nCmdShow).test();
}

std::string SwapchainResolutionTester::testViewport()
{
	return SwapchainResolutionViewportTest(hInstance, nCmdShow).test();
}
