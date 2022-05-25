#include "ResolutionMinimumTester.h"

ResolutionMinimumTester::ResolutionMinimumTester()
{
}

ResolutionMinimumTester::~ResolutionMinimumTester()
{
}

std::string ResolutionMinimumTester::test()
{
	std::string failures{ "" };

	failures += testWidth();
	failures += testHeight();

	return failures;
}

std::string ResolutionMinimumTester::testWidth()
{
	return ResolutionMinimumWidthTest().test();
}

std::string ResolutionMinimumTester::testHeight()
{
	return ResolutionMinimumHeightTest().test();
}
