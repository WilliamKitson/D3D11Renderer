#include "ImplimentationTester.h"

ImplimentationTester::ImplimentationTester(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }
{
}

ImplimentationTester::~ImplimentationTester()
{
}

std::string ImplimentationTester::test()
{
	std::string output{ "" };

	output += testResolution();
	output += testSync();
	output += testDraw();
	output += testCull();

	return output;
}

std::string ImplimentationTester::testResolution()
{
	return ImplimentationResolutionTester(hInstance, nCmdShow).test();
}

std::string ImplimentationTester::testSync()
{
	return ImplimentationSyncTester(hInstance, nCmdShow).test();
}

std::string ImplimentationTester::testDraw()
{
	return ImplimentationDrawTester(hInstance, nCmdShow).test();
}

std::string ImplimentationTester::testCull()
{
	return ImplimentationCullTester(hInstance, nCmdShow).test();
}
