#include "SubordinateTester.h"

SubordinateTester::SubordinateTester(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }
{
}

SubordinateTester::~SubordinateTester()
{
}

std::string SubordinateTester::test()
{
	std::string failures{ "" };

	failures += testDomain();
	failures += testApplication();

	return failures;
}

std::string SubordinateTester::testDomain()
{
	return DomainTester().test();
}

std::string SubordinateTester::testApplication()
{
	return ApplicationTester(hInstance, nCmdShow).test();
}
