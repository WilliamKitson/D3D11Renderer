#include "RasteriserModeTester.h"

RasteriserModeTester::RasteriserModeTester()
{
}

RasteriserModeTester::~RasteriserModeTester()
{
}

std::string RasteriserModeTester::test()
{
	std::string failures{ "" };

	failures += testWireframe();
	failures += testSolid();

	return failures;
}

std::string RasteriserModeTester::testWireframe()
{
	return RasteriserModeWireframeTest().test();
}

std::string RasteriserModeTester::testSolid()
{
	return RasteriserModeSolidTest().test();
}
