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

	return output;
}

std::string SwapchainTester::testDefault()
{
	return SwapchainDefaultTester(hInstance, nCmdShow).test();
}
