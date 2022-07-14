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

	return output;
}

std::string InterleavedTester::testDefault()
{
	return InterleavedDefaultTest().test();
}
