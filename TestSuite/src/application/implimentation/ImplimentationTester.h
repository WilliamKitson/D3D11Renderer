#pragma once

#include <string>

#include "resolution/ImplimentationResolutionTester.h"
#include "sync/ImplimentationSyncTester.h"

class ImplimentationTester
{
public:
	ImplimentationTester(HINSTANCE, int);
	~ImplimentationTester();

	std::string test();

private:
	std::string testResolution();
	std::string testSync();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
