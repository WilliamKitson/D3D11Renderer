#pragma once

#include <string>

#include "SwapchainInvalidDeviceTest.h"
#include "SwapchainInvalidWindowTest.h"
#include "SwapchainInvalidBindTest.h"
#include "SwapchainInvalidUpdateTest.h"
#include "SwapchainInvalidStateTest.h"

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

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
