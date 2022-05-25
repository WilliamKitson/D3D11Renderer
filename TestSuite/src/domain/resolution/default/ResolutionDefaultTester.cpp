#include "ResolutionDefaultTester.h"

ResolutionDefaultTester::ResolutionDefaultTester()
{
}

ResolutionDefaultTester::~ResolutionDefaultTester()
{
}

std::string ResolutionDefaultTester::test()
{
	std::string failures{ "" };

	failures += testWidth();
	failures += testHeight();

	return failures;
}

std::string ResolutionDefaultTester::testWidth()
{
	return ResolutionDefaultWidthTest().test();
}

std::string ResolutionDefaultTester::testHeight()
{
	return ResolutionDefaultHeightTest().test();
}
