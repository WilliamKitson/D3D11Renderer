#pragma once

#include <string>
#include "ImplimentationDrawDefaultTest.h"

class ImplimentationDrawTester
{
public:
	ImplimentationDrawTester(HINSTANCE, int);
	~ImplimentationDrawTester();

	std::string test();

private:
	std::string testDefault();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
