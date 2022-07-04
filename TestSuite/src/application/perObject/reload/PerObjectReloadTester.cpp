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

	output += testTransform();
	output += testColour();

	return output;
}

std::string PerObjectReloadTester::testTransform()
{
	return PerObjectReloadTransformTest().test();
}

std::string PerObjectReloadTester::testColour()
{
	return PerObjectReloadColourTest().test();
}
