#pragma once

#include <string>

#include "ImplimentationSyncDefaultTest.h"
#include "ImplimentationSyncFullTest.h"

class ImplimentationSyncTester
{
public:
	ImplimentationSyncTester(HINSTANCE, int);
	~ImplimentationSyncTester();

	std::string test();

private:
	std::string testDefault();
	std::string testFull();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
