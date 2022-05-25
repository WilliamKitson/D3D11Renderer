#include "SubordinateTester.h"

SubordinateTester::SubordinateTester()
{
}

SubordinateTester::~SubordinateTester()
{
}

std::string SubordinateTester::test()
{
	std::string failures{ "" };

	failures += testPresentation();

	return failures;
}

std::string SubordinateTester::testPresentation()
{
	return PresentationTester().test();
}
