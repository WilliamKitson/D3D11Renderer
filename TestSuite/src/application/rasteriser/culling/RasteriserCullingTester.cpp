#include "RasteriserCullingTester.h"

RasteriserCullingTester::RasteriserCullingTester()
{
}

RasteriserCullingTester::~RasteriserCullingTester()
{
}

std::string RasteriserCullingTester::test()
{
	std::string output{ "" };

	output += testNone();
	output += testFront();
	output += testBack();

	return output;
}

std::string RasteriserCullingTester::testNone()
{
	return RasteriserCullingNoneTest().test();
}

std::string RasteriserCullingTester::testFront()
{
	return RasteriserCullingFrontTest().test();
}

std::string RasteriserCullingTester::testBack()
{
	return RasteriserCullingBackTest().test();
}
