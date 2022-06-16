#pragma once

#include <string>
#include <Windows.h>

#include "SwapchainIntervalDefaultTest.h"

class SwapchainIntervalTester
{
public:
	SwapchainIntervalTester(HINSTANCE, int);
	~SwapchainIntervalTester();

	std::string test();

private:
	std::string testDefault();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
