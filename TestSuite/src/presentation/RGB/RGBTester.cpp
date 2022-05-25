#include "RGBTester.h"

RGBTester::RGBTester()
{
}

RGBTester::~RGBTester()
{
}

std::string RGBTester::test()
{
	std::string failures{ "" };

	failures += testRed();

	return failures;
}

std::string RGBTester::testRed()
{
	return RGBRedTest().test();
}
