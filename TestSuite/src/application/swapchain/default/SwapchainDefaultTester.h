#pragma once

#include <string>
#include "SwapchainDefaultViewportTest.h"

class SwapchainDefaultTester
{
public:
	SwapchainDefaultTester(HINSTANCE, int);
	~SwapchainDefaultTester();

	std::string test();

private:
	std::string testViewport();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
