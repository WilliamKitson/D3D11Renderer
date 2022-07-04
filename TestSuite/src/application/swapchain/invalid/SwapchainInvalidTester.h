#pragma once

#include <string>

#include "SwapchainInvalidDeviceTest.h"
#include "SwapchainInvalidWindowTest.h"
#include "SwapchainInvalidContextTest.h"

class SwapchainInvalidTester
{
public:
	SwapchainInvalidTester(HINSTANCE, int);
	~SwapchainInvalidTester();

	std::string test();

private:
	std::string testDevice();
	std::string testWindow();
	std::string testContext();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
