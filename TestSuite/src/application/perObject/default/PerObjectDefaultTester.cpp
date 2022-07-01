#include "PerObjectDefaultTester.h"

PerObjectDefaultTester::PerObjectDefaultTester()
{
}

PerObjectDefaultTester::~PerObjectDefaultTester()
{
}

std::string PerObjectDefaultTester::test()
{
	std::string output{ "" };

	output += testTransform();

	return output;
}

std::string PerObjectDefaultTester::testTransform()
{
	return PerObjectDefaultTransformTest().test();
}
