#pragma once

#include <string>
#include <Windows.h>

#include "SwapchainResolutionViewTest.h"
#include "SwapchainResolutionDepthTest.h"
#include "SwapchainResolutionViewportTest.h"

class SwapchainResolutionTester
{
public:
	SwapchainResolutionTester(HINSTANCE, int);
	~SwapchainResolutionTester();

	std::string test();

private:
	std::string testView();
	std::string testDepth();
	std::string testViewport();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
