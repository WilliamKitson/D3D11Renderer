#pragma once

#include <string>
#include <Windows.h>

#include "SwapchainResolutionViewTest.h"

class SwapchainResolutionTester
{
public:
	SwapchainResolutionTester(HINSTANCE, int);
	~SwapchainResolutionTester();

	std::string test();

private:
	std::string testView();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
