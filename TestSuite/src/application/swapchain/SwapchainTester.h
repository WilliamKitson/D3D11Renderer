#pragma once

#include <string>
#include "default/SwapchainDefaultTester.h"

class SwapchainTester
{
public:
	SwapchainTester(HINSTANCE, int);
	~SwapchainTester();

	std::string test();

private:
	std::string testDefault();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
