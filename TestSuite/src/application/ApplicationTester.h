#pragma once

#include <string>

#include "swapchain/SwapchainTester.h"
#include "shaders/ShadersTester.h"
#include "rasteriser/RasteriserTester.h"
#include "sampler/SamplerTester.h"
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
	std::string testShaders();
	std::string testRasteriser();
	std::string testSampler();
	std::string testPerScene();
	std::string testPerObject();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
