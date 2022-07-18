#pragma once

#include <string>
#include "ImplimentationSyncDefaultTest.h"

class ImplimentationSyncTester
{
public:
	ImplimentationSyncTester(HINSTANCE, int);
	~ImplimentationSyncTester();

	std::string test();

private:
	std::string testDefault();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
