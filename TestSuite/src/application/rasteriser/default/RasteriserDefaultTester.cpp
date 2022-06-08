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
	failures += testCulling();

	return failures;
}

std::string RasteriserDefaultTester::testMode()
{
	return RasteriserDefaultModeTest().test();
}

std::string RasteriserDefaultTester::testCulling()
{
	return RasteriserDefaultCullingTest().test();
}
