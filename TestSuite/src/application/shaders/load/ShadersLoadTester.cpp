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

	return output;
}

std::string ShadersLoadTester::testVertex()
{
	return ShadersLoadVertexTest().test();
}
