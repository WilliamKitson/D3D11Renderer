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
	failures += testGreen();
	failures += testBlue();

	return failures;
}

std::string RGBTester::testRed()
{
	return RGBRedTest().test();
}

std::string RGBTester::testGreen()
{
	return RGBGreenTest().test();
}

std::string RGBTester::testBlue()
{
	return RGBBlueTest().test();
}
