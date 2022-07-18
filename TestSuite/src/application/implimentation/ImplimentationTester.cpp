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

	return output;
}

std::string ImplimentationTester::testResolution()
{
	return ImplimentationResolutionTester(hInstance, nCmdShow).test();
}
