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

	return output;
}

std::string PerObjectUpdateTester::testTransform()
{
	return PerObjectUpdateTransformTest().test();
}
