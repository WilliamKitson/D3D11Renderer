#pragma once

#include <string>

#include "ImplimentationCullDefaultTest.h"
#include "ImplimentationCullNoneTest.h"
#include "ImplimentationCullFrontTest.h"

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

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
