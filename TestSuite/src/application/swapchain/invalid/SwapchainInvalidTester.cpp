#include "SwapchainInvalidTester.h"

SwapchainInvalidTester::SwapchainInvalidTester(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }
{
}

SwapchainInvalidTester::~SwapchainInvalidTester()
{
}

std::string SwapchainInvalidTester::test()
{
	std::string output{ "" };

	output += testDevice();
	output += testWindow();
	output += testContext();

	return output;
}

std::string SwapchainInvalidTester::testDevice()
{
	return SwapchainInvalidDeviceTest(hInstance, nCmdShow).test();
}

std::string SwapchainInvalidTester::testWindow()
{
	return SwapchainInvalidWindowTest(hInstance, nCmdShow).test();
}

std::string SwapchainInvalidTester::testContext()
{
	return SwapchainInvalidContextTest(hInstance, nCmdShow).test();
}
