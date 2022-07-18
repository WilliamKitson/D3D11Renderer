#include "ImplimentationDrawTester.h"

ImplimentationDrawTester::ImplimentationDrawTester(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }
{
}

ImplimentationDrawTester::~ImplimentationDrawTester()
{
}

std::string ImplimentationDrawTester::test()
{
	std::string output{ "" };

	output += testDefault();
	output += testWireframe();

	return output;
}

std::string ImplimentationDrawTester::testDefault()
{
	return ImplimentationDrawDefaultTest(hInstance, nCmdShow).test();
}

std::string ImplimentationDrawTester::testWireframe()
{
	return ImplimentationDrawWireframeTest(hInstance, nCmdShow).test();
}
