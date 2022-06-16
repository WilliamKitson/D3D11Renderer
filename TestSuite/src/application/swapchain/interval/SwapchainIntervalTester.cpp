#include "SwapchainIntervalTester.h"

SwapchainIntervalTester::SwapchainIntervalTester(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }
{
}

SwapchainIntervalTester::~SwapchainIntervalTester()
{
}

std::string SwapchainIntervalTester::test()
{
	std::string output{ "" };

	output += testDefault();

	return output;
}

std::string SwapchainIntervalTester::testDefault()
{
	return SwapchainIntervalDefaultTest(hInstance, nCmdShow).test();
}
