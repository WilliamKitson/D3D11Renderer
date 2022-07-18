#pragma once

#include <string>
#include "resolution/ImplimentationResolutionTester.h"

class ImplimentationTester
{
public:
	ImplimentationTester(HINSTANCE, int);
	~ImplimentationTester();

	std::string test();

private:
	std::string testResolution();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
