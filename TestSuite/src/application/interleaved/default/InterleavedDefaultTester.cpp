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
	output += testIndex();

	return output;
}

std::string InterleavedDefaultTester::testVertex()
{
	return InterleavedDefaultVertexTest().test();
}

std::string InterleavedDefaultTester::testIndex()
{
	return InterleavedDefaultIndexTest().test();
}
