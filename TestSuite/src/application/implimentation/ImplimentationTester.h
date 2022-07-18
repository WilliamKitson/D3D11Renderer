#pragma once

#include <string>

#include "resolution/ImplimentationResolutionTester.h"
#include "sync/ImplimentationSyncTester.h"
#include "draw/ImplimentationDrawTester.h"
#include "cull/ImplimentationCullTester.h"

class ImplimentationTester
{
public:
	ImplimentationTester(HINSTANCE, int);
	~ImplimentationTester();

	std::string test();

private:
	std::string testResolution();
	std::string testSync();
	std::string testDraw();
	std::string testCull();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
