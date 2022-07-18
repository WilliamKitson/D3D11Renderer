#pragma once

#include <string>

#include "ImplimentationSyncDefaultTest.h"
#include "ImplimentationSyncFullTest.h"
#include "ImplimentationSyncHalfTest.h"
#include "ImplimentationSyncQuaterTest.h"

class ImplimentationSyncTester
{
public:
	ImplimentationSyncTester(HINSTANCE, int);
	~ImplimentationSyncTester();

	std::string test();

private:
	std::string testDefault();
	std::string testFull();
	std::string testHalf();
	std::string testQuater();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
