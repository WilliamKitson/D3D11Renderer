#include "ImplimentationSceneTester.h"

ImplimentationSceneTester::ImplimentationSceneTester()
{
}

ImplimentationSceneTester::~ImplimentationSceneTester()
{
}

std::string ImplimentationSceneTester::test()
{
	std::string output{ "" };

	output += testDefault();

	return output;
}

std::string ImplimentationSceneTester::testDefault()
{
	return ImplimentationSceneDefaultTest().test();
}
