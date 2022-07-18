#pragma once

#include <string>

#include "ImplimentationCullDefaultTest.h"
#include "ImplimentationCullNoneTest.h"

class ImplimentationCullTester
{
public:
	ImplimentationCullTester(HINSTANCE, int);
	~ImplimentationCullTester();

	std::string test();

private:
	std::string testDefault();
	std::string testNone();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
