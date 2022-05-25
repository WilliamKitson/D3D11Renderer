#include "ApplicationTester.h"

ApplicationTester::ApplicationTester()
{
}

ApplicationTester::~ApplicationTester()
{
}

std::string ApplicationTester::test()
{
	std::string failures{ "" };

	failures += testRasteriser();

	return failures;
}

std::string ApplicationTester::testRasteriser()
{
	return RasteriserTester().test();
}
