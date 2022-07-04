#include "SwapchainTester.h"

SwapchainTester::SwapchainTester(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }
{
}

SwapchainTester::~SwapchainTester()
{
}

std::string SwapchainTester::test()
{
	std::string output{ "" };

	output += testDefault();
	output += testResolution();
	output += testInterval();
	output += testInvalid();

	return output;
}

std::string SwapchainTester::testDefault()
{
	return SwapchainDefaultTester(hInstance, nCmdShow).test();
}

std::string SwapchainTester::testResolution()
{
	return SwapchainResolutionTester(hInstance, nCmdShow).test();
}

std::string SwapchainTester::testInterval()
{
	return SwapchainIntervalTester(hInstance, nCmdShow).test();
}

std::string SwapchainTester::testInvalid()
{
	return SwapchainInvalidTester(hInstance, nCmdShow).test();
}
