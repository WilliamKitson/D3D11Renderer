#include "ResolutionTester.h"

ResolutionTester::ResolutionTester()
{
}

ResolutionTester::~ResolutionTester()
{
}

std::string ResolutionTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testParameter();
	failures += testMinimum();

	return failures;
}

std::string ResolutionTester::testDefault()
{
	return ResolutionDefaultTester().test();
}

std::string ResolutionTester::testParameter()
{
	return ResolutionParameterTester().test();
}

std::string ResolutionTester::testMinimum()
{
	return ResolutionMinimumTester().test();
}
