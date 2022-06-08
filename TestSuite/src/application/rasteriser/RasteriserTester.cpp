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
