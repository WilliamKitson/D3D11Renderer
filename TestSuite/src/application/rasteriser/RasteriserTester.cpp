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

	return failures;
}

std::string RasteriserTester::testDefault()
{
	return RasteriserDefaultTester().test();
}
