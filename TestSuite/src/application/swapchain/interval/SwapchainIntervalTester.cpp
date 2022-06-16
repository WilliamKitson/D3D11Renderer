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
	output += testFull();
	output += testHalf();

	return output;
}

std::string SwapchainIntervalTester::testDefault()
{
	return SwapchainIntervalDefaultTest(hInstance, nCmdShow).test();
}

std::string SwapchainIntervalTester::testFull()
{
	return SwapchainIntervalFullTest(hInstance, nCmdShow).test();
}

std::string SwapchainIntervalTester::testHalf()
{
	return SwapchainIntervalHalfTest(hInstance, nCmdShow).test();
}
