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

	failures += testDomain();
	failures += testPresentation();

	return failures;
}

std::string SubordinateTester::testDomain()
{
	return DomainTester().test();
}

std::string SubordinateTester::testPresentation()
{
	return PresentationTester().test();
}
