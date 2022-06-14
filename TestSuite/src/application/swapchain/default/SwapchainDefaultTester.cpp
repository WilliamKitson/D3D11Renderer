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

	output += testViewport();

	return output;
}

std::string SwapchainDefaultTester::testViewport()
{
	return SwapchainDefaultViewportTest(hInstance, nCmdShow).test();
}
