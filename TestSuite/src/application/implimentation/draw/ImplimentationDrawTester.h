#pragma once

#include <string>

#include "ImplimentationDrawDefaultTest.h"
#include "ImplimentationDrawWireframeTest.h"
#include "ImplimentationDrawSolidTest.h"

class ImplimentationDrawTester
{
public:
	ImplimentationDrawTester(HINSTANCE, int);
	~ImplimentationDrawTester();

	std::string test();

private:
	std::string testDefault();
	std::string testWireframe();
	std::string testSolid();

private:
	HINSTANCE hInstance;
	int nCmdShow;
};
