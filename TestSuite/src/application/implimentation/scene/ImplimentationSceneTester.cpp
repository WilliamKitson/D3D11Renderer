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
	output += testCamera();
	output += testAmbience();

	return output;
}

std::string ImplimentationSceneTester::testDefault()
{
	return ImplimentationSceneDefaultTest().test();
}

std::string ImplimentationSceneTester::testCamera()
{
	return ImplimentationSceneCameraTest().test();
}

std::string ImplimentationSceneTester::testAmbience()
{
	return ImplimentationSceneAmbienceTest().test();
}
