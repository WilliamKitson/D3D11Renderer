#include "ShadersLoadTester.h"

ShadersLoadTester::ShadersLoadTester()
{
}

ShadersLoadTester::~ShadersLoadTester()
{
}

std::string ShadersLoadTester::test()
{
	std::string output{ "" };

	output += testVertex();
	output += testPixel();

	return output;
}

std::string ShadersLoadTester::testVertex()
{
	return ShadersLoadVertexTest().test();
}

std::string ShadersLoadTester::testPixel()
{
	return ShadersLoadPixelTest().test();
}
