#pragma once

#include <string>

#include "SwapchainInvalidDeviceTest.h"
#include "SwapchainInvalidWindowTest.h"

class SwapchainInvalidTester
{
public:
	SwapchainInvalidTester(HINSTANCE, int);
	~SwapchainInvalidTester();

	std::string test();

private:
	std::string testDevice();
	std::string testWindow();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
