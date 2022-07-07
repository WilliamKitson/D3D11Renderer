#include "Coordinates1DCountTester.h"

Coordinates1DCountTester::Coordinates1DCountTester()
{
}

Coordinates1DCountTester::~Coordinates1DCountTester()
{
}

std::string Coordinates1DCountTester::test()
{
	std::string output{ "" };

	output += testDefault();

	return output;
}

std::string Coordinates1DCountTester::testDefault()
{
	return Coordinates1DCountDefaultTest().test();
}
