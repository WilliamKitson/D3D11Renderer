#pragma once

#include <string>

#include "SwapchainInvalidDeviceTest.h"
#include "SwapchainInvalidWindowTest.h"
#include "SwapchainInvalidBindTest.h"
#include "SwapchainInvalidUpdateTest.h"

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

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
