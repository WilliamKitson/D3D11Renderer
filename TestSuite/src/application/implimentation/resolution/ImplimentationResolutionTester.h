#pragma once

#include <string>

#include "ImplimentationResolutionDefaultTest.h"
#include "ImplimentationResolutionReloadTest.h"

class ImplimentationResolutionTester
{
public:
	ImplimentationResolutionTester(HINSTANCE, int);
	~ImplimentationResolutionTester();

	std::string test();

private:
	std::string testDefault();
	std::string testReload();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
