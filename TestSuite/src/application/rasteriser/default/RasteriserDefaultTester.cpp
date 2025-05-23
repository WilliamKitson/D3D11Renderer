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
	failures += testDepth();

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

std::string RasteriserDefaultTester::testDepth()
{
	return RasteriserDefaultDepthTest().test();
}
