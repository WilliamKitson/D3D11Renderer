#include "ImplimentationResolutionTester.h"

ImplimentationResolutionTester::ImplimentationResolutionTester(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }
{
}

ImplimentationResolutionTester::~ImplimentationResolutionTester()
{
}

std::string ImplimentationResolutionTester::test()
{
	std::string output{ "" };

	output += testDefault();
	output += testReload();

	return output;
}

std::string ImplimentationResolutionTester::testDefault()
{
	return ImplimentationResolutionDefaultTest(hInstance, nCmdShow).test();
}

std::string ImplimentationResolutionTester::testReload()
{
	return ImplimentationResolutionReloadTest(hInstance, nCmdShow).test();
}
