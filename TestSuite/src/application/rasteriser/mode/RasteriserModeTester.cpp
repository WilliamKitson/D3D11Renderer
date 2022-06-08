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

	return failures;
}

std::string RasteriserModeTester::testWireframe()
{
	return RasteriserModeWireframeTest().test();
}
