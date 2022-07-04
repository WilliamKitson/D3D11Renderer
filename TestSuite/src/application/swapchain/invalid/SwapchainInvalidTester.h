#pragma once

#include <string>
#include "SwapchainInvalidDeviceTest.h"

class SwapchainInvalidTester
{
public:
	SwapchainInvalidTester(HINSTANCE, int);
	~SwapchainInvalidTester();

	std::string test();

private:
	std::string testDevice();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
