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

	return failures;
}

std::string RGBATester::testRed()
{
	return RGBARedTest().test();
}
