#include "ImplimentationObjectTester.h"

ImplimentationObjectTester::ImplimentationObjectTester()
{
}

ImplimentationObjectTester::~ImplimentationObjectTester()
{
}

std::string ImplimentationObjectTester::test()
{
	std::string output{ "" };

	output += testDefault();
	output += testTransform();
	output += testColour();

	return output;
}

std::string ImplimentationObjectTester::testDefault()
{
	return ImplimentationObjectDefaultTest().test();
}

std::string ImplimentationObjectTester::testTransform()
{
	return ImplimentationObjectTransformTest().test();
}

std::string ImplimentationObjectTester::testColour()
{
	return ImplimentationObjectColourTest().test();
}
