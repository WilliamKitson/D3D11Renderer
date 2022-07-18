#pragma once

#include <string>

#include "ImplimentationSyncDefaultTest.h"
#include "ImplimentationSyncFullTest.h"
#include "ImplimentationSyncHalfTest.h"

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

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
