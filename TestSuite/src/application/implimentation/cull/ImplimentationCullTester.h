#pragma once

#include <string>
#include "ImplimentationCullDefaultTest.h"

class ImplimentationCullTester
{
public:
	ImplimentationCullTester(HINSTANCE, int);
	~ImplimentationCullTester();

	std::string test();

private:
	std::string testDefault();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
