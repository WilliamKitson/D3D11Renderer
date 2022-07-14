#include "InterleavedDefaultTester.h"

InterleavedDefaultTester::InterleavedDefaultTester()
{
}

InterleavedDefaultTester::~InterleavedDefaultTester()
{
}

std::string InterleavedDefaultTester::test()
{
	std::string output{ "" };

	output += testVertex();

	return output;
}

std::string InterleavedDefaultTester::testVertex()
{
	return InterleavedDefaultVertexTest().test();
}
