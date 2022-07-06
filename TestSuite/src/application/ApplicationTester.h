#pragma once

#include <string>

#include "swapchain/SwapchainTester.h"
#include "rasteriser/RasteriserTester.h"
#include "perScene/PerSceneTester.h"
#include "perObject/PerObjectTester.h"

class ApplicationTester
{
public:
	ApplicationTester(HINSTANCE, int);
	~ApplicationTester();

	std::string test();

private:
	std::string testSwapchain();
	std::string testRasteriser();
	std::string testPerScene();
	std::string testPerObject();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
