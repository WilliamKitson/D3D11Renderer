#include "PerObjectReloadTester.h"

PerObjectReloadTester::PerObjectReloadTester()
{
}

PerObjectReloadTester::~PerObjectReloadTester()
{
}

std::string PerObjectReloadTester::test()
{
	std::string output{ "" };

	output += testColour();

	return output;
}

std::string PerObjectReloadTester::testColour()
{
	return PerObjectReloadColourTest().test();
}
