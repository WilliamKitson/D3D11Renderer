#include "PerObjectApplyTester.h"

PerObjectApplyTester::PerObjectApplyTester()
{
}

PerObjectApplyTester::~PerObjectApplyTester()
{
}

std::string PerObjectApplyTester::test()
{
	std::string output{ "" };

	output += testTransform();
	output += testColour();

	return output;
}

std::string PerObjectApplyTester::testTransform()
{
	return PerObjectApplyTransformTest().test();
}

std::string PerObjectApplyTester::testColour()
{
	return PerObjectApplyColourTest().test();
}
