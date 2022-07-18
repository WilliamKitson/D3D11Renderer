#include "DomainTester.h"

DomainTester::DomainTester()
{
}

DomainTester::~DomainTester()
{
}

std::string DomainTester::test()
{
	std::string output{ "" };

	output += testResolution();

	return output;
}

std::string DomainTester::testResolution()
{
	return ResolutionTester().test();
}
