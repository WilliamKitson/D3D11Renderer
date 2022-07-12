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
	output += testBind();
	output += testUpdate();
	output += testState();

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

std::string SwapchainInvalidTester::testBind()
{
	return SwapchainInvalidBindTest(hInstance, nCmdShow).test();
}

std::string SwapchainInvalidTester::testUpdate()
{
	return SwapchainInvalidUpdateTest(hInstance, nCmdShow).test();
}

std::string SwapchainInvalidTester::testState()
{
	return SwapchainInvalidStateTest(hInstance, nCmdShow).test();
}
