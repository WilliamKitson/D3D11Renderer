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

	return output;
}

std::string RasteriserCullingTester::testNone()
{
	return RasteriserCullingNoneTest().test();
}
