#pragma once

#include <string>
#include "ImplimentationResolutionDefaultTest.h"

class ImplimentationResolutionTester
{
public:
	ImplimentationResolutionTester(HINSTANCE, int);
	~ImplimentationResolutionTester();

	std::string test();

private:
	std::string testDefault();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
