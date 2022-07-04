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

	return output;
}

std::string PerObjectApplyTester::testTransform()
{
	return PerObjectApplyTransformTest().test();
}
