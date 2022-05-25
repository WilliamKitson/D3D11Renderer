#include "RGBATester.h"

RGBATester::RGBATester()
{
}

RGBATester::~RGBATester()
{
}

std::string RGBATester::test()
{
	std::string failures{ "" };

	failures += testRed();
	failures += testGreen();
	failures += testBlue();
	failures += testAlpha();

	return failures;
}

std::string RGBATester::testRed()
{
	return RGBARedTest().test();
}

std::string RGBATester::testGreen()
{
	return RGBAGreenTest().test();
}

std::string RGBATester::testBlue()
{
	return RGBABlueTest().test();
}

std::string RGBATester::testAlpha()
{
	return RGBAAlphaTest().test();
}
