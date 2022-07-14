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
