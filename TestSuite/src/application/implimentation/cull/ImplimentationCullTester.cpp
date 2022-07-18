#include "ImplimentationCullTester.h"

ImplimentationCullTester::ImplimentationCullTester(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }
{
}

ImplimentationCullTester::~ImplimentationCullTester()
{
}

std::string ImplimentationCullTester::test()
{
	std::string output{ "" };

	output += testDefault();

	return output;
}

std::string ImplimentationCullTester::testDefault()
{
	return ImplimentationCullDefaultTest(hInstance, nCmdShow).test();
}
