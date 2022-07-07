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
	failures += testCoordinates3D();

	return failures;
}

std::string DomainTester::testResolution()
{
	return ResolutionTester().test();
}

std::string DomainTester::testCoordinates3D()
{
	return Coordinates3DTester().test();
}
