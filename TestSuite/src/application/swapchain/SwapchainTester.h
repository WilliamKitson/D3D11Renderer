#pragma once

#include <string>

#include "default/SwapchainDefaultTester.h"
#include "resolution/SwapchainResolutionTester.h"
#include "interval/SwapchainIntervalTester.h"

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

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
