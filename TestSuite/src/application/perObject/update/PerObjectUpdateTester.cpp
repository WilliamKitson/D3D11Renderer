#include "PerObjectUpdateTester.h"

PerObjectUpdateTester::PerObjectUpdateTester()
{
}

PerObjectUpdateTester::~PerObjectUpdateTester()
{
}

std::string PerObjectUpdateTester::test()
{
	std::string output{ "" };

	output += testTransform();
	output += testColour();

	return output;
}

std::string PerObjectUpdateTester::testTransform()
{
	return PerObjectReloadTransformTest().test();
}

std::string PerObjectUpdateTester::testColour()
{
	return PerObjectUpdateColourTest().test();
}
