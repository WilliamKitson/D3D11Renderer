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
	output += testNone();

	return output;
}

std::string ImplimentationCullTester::testDefault()
{
	return ImplimentationCullDefaultTest(hInstance, nCmdShow).test();
}

std::string ImplimentationCullTester::testNone()
{
	return ImplimentationCullNoneTest(hInstance, nCmdShow).test();
}
