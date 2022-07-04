#pragma once

#include <string>

#include "default/SwapchainDefaultTester.h"
#include "resolution/SwapchainResolutionTester.h"
#include "interval/SwapchainIntervalTester.h"
#include "invalid/SwapchainInvalidTester.h"

class SwapchainTester
{
public:
	SwapchainTester(HINSTANCE, int);
	~SwapchainTester();

	std::string test();

private:
	std::string testDefault();
	std::string testResolution();
	std::string testInterval();
	std::string testInvalid();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
