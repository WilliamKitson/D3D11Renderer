#pragma once

#include <string>

#include "swapchain/SwapchainTester.h"
#include "rasteriser/RasteriserTester.h"

class ApplicationTester
{
public:
	ApplicationTester(HINSTANCE, int);
	~ApplicationTester();

	std::string test();

private:
	std::string testSwapchain();
	std::string testRasteriser();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
