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
	output += testFull();
	output += testHalf();

	return output;
}

std::string ImplimentationSyncTester::testDefault()
{
	return ImplimentationSyncDefaultTest(hInstance, nCmdShow).test();
}

std::string ImplimentationSyncTester::testFull()
{
	return ImplimentationSyncFullTest(hInstance, nCmdShow).test();
}

std::string ImplimentationSyncTester::testHalf()
{
	return ImplimentationSyncHalfTest(hInstance, nCmdShow).test();
}
