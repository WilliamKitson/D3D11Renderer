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
	output += testColour();

	return output;
}

std::string PerObjectDefaultTester::testTransform()
{
	return PerObjectDefaultTransformTest().test();
}

std::string PerObjectDefaultTester::testColour()
{
	return PerObjectDefaultColourTest().test();
}
