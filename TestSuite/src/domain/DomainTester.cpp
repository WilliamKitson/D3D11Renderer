#include "DomainTester.h"

DomainTester::DomainTester()
{
}

DomainTester::~DomainTester()
{
}

std::string DomainTester::test()
{
	std::string failures{ "" };

	failures += testResolution();

	return failures;
}

std::string DomainTester::testResolution()
{
	return ResolutionTester().test();
}
