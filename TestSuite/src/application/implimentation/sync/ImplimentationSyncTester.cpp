#include "ImplimentationSyncTester.h"

ImplimentationSyncTester::ImplimentationSyncTester(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }
{
}

ImplimentationSyncTester::~ImplimentationSyncTester()
{
}

std::string ImplimentationSyncTester::test()
{
	std::string output{ "" };

	output += testDefault();

	return output;
}

std::string ImplimentationSyncTester::testDefault()
{
	return ImplimentationSyncDefaultTest(hInstance, nCmdShow).test();
}
