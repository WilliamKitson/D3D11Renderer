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

	return output;
}

std::string ImplimentationObjectTester::testDefault()
{
	return ImplimentationObjectDefaultTest().test();
}
