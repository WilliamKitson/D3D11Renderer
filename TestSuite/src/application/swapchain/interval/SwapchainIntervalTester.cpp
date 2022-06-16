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
	output += testQuater();
	output += testNone();

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

std::string SwapchainIntervalTester::testQuater()
{
	return SwapchainIntervalQuaterTest(hInstance, nCmdShow).test();
}

std::string SwapchainIntervalTester::testNone()
{
	return SwapchainIntervalNoneTest(hInstance, nCmdShow).test();
}
