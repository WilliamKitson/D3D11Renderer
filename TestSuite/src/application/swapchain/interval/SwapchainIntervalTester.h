#pragma once

#include <string>
#include <Windows.h>

#include "SwapchainIntervalDefaultTest.h"
#include "SwapchainIntervalFullTest.h"

class SwapchainIntervalTester
{
public:
	SwapchainIntervalTester(HINSTANCE, int);
	~SwapchainIntervalTester();

	std::string test();

private:
	std::string testDefault();
	std::string testFull();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
