#pragma once

#include <string>

#include "SwapchainDefaultViewTest.h"
#include "SwapchainDefaultDepthTest.h"
#include "SwapchainDefaultViewportTest.h"

class SwapchainDefaultTester
{
public:
	SwapchainDefaultTester(HINSTANCE, int);
	~SwapchainDefaultTester();

	std::string test();

private:
	std::string testView();
	std::string testDepth();
	std::string testViewport();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
