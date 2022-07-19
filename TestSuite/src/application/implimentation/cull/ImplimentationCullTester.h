#pragma once

#include <string>

#include "ImplimentationCullDefaultTest.h"
#include "ImplimentationCullNoneTest.h"
#include "ImplimentationCullFrontTest.h"
#include "ImplimentationCullBackTest.h"

class ImplimentationCullTester
{
public:
	ImplimentationCullTester(HINSTANCE, int);
	~ImplimentationCullTester();

	std::string test();

private:
	std::string testDefault();
	std::string testNone();
	std::string testFront();
	std::string testBack();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
