#include "SwapchainDefaultTester.h"

SwapchainDefaultTester::SwapchainDefaultTester(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }
{
}

SwapchainDefaultTester::~SwapchainDefaultTester()
{
}

std::string SwapchainDefaultTester::test()
{
	std::string output{ "" };

	output += testView();
	output += testDepth();
	output += testViewport();

	return output;
}

std::string SwapchainDefaultTester::testView()
{
	return SwapchainDefaultViewTest(hInstance, nCmdShow).test();
}

std::string SwapchainDefaultTester::testDepth()
{
	return SwapchainDefaultDepthTest(hInstance, nCmdShow).test();
}

std::string SwapchainDefaultTester::testViewport()
{
	return SwapchainDefaultViewportTest(hInstance, nCmdShow).test();
}
