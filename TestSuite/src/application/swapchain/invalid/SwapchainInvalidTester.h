#pragma once

#include <string>

#include "SwapchainInvalidDeviceTest.h"
#include "SwapchainInvalidWindowTest.h"
#include "SwapchainInvalidBindTest.h"
#include "SwapchainInvalidUpdateTest.h"
#include "SwapchainInvalidStateTest.h"
#include "SwapchainInvalidOverlapTest.h"

class SwapchainInvalidTester
{
public:
	SwapchainInvalidTester(HINSTANCE, int);
	~SwapchainInvalidTester();

	std::string test();

private:
	std::string testDevice();
	std::string testWindow();
	std::string testBind();
	std::string testUpdate();
	std::string testState();
	std::string testOverlap();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
