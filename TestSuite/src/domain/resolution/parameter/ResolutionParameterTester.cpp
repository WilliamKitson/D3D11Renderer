#include "ResolutionParameterTester.h"

ResolutionParameterTester::ResolutionParameterTester()
{
}

ResolutionParameterTester::~ResolutionParameterTester()
{
}

std::string ResolutionParameterTester::test()
{
	std::string failures{ "" };

	failures += testWidth();
	failures += testHeight();

	return failures;
}

std::string ResolutionParameterTester::testWidth()
{
	return ResolutionParameterWidthTest().test();
}

std::string ResolutionParameterTester::testHeight()
{
	return ResolutionParameterHeightTest().test();
}
