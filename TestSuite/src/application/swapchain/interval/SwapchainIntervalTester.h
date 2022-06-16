#pragma once

#include <string>
#include <Windows.h>

#include "SwapchainIntervalDefaultTest.h"
#include "SwapchainIntervalFullTest.h"
#include "SwapchainIntervalHalfTest.h"
#include "SwapchainIntervalQuaterTest.h"
#include "SwapchainIntervalNoneTest.h"

class SwapchainIntervalTester
{
public:
	SwapchainIntervalTester(HINSTANCE, int);
	~SwapchainIntervalTester();

	std::string test();

private:
	std::string testDefault();
	std::string testFull();
	std::string testHalf();
	std::string testQuater();
	std::string testNone();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
