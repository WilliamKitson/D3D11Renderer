#include "RasteriserTester.h"

RasteriserTester::RasteriserTester()
{
}

RasteriserTester::~RasteriserTester()
{
}

std::string RasteriserTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testMode();
	failures += testCulling();
	failures += testInvalid();

	return failures;
}

std::string RasteriserTester::testDefault()
{
	return RasteriserDefaultTester().test();
}

std::string RasteriserTester::testMode()
{
	return RasteriserModeTester().test();
}

std::string RasteriserTester::testCulling()
{
	return RasteriserCullingTester().test();
}

std::string RasteriserTester::testInvalid()
{
	return RasteriserInvalidTester().test();
}
