#include "RasteriserDefaultTester.h"

RasteriserDefaultTester::RasteriserDefaultTester()
{
}

RasteriserDefaultTester::~RasteriserDefaultTester()
{
}

std::string RasteriserDefaultTester::test()
{
	std::string failures{ "" };

	failures += testMode();

	return failures;
}

std::string RasteriserDefaultTester::testMode()
{
	return RasteriserDefaultModeTest().test();
}
