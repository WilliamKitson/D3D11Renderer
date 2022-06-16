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

	return output;
}

std::string SwapchainResolutionTester::testView()
{
	return SwapchainResolutionViewTest(hInstance, nCmdShow).test();
}
