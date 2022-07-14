#include "InterleavedTester.h"

InterleavedTester::InterleavedTester()
{
}

InterleavedTester::~InterleavedTester()
{
}

std::string InterleavedTester::test()
{
	std::string output{ "" };

	output += testDefault();
	output += testReload();
	output += testStride();

	return output;
}

std::string InterleavedTester::testDefault()
{
	return InterleavedDefaultTest().test();
}

std::string InterleavedTester::testReload()
{
	return InterleavedReloadTest().test();
}

std::string InterleavedTester::testStride()
{
	return InterleavedStrideTest().test();
}
