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
	failures += testCoordinates1D();

	return failures;
}

std::string DomainTester::testResolution()
{
	return ResolutionTester().test();
}

std::string DomainTester::testCoordinates1D()
{
	return Coordinates1DTester().test();
}
