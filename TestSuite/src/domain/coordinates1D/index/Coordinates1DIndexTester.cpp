#include "Coordinates1DIndexTester.h"

Coordinates1DIndexTester::Coordinates1DIndexTester()
{
}

Coordinates1DIndexTester::~Coordinates1DIndexTester()
{
}

std::string Coordinates1DIndexTester::test()
{
	std::string output{ "" };

	output += testDefault();
	output += testMinimum();

	return output;
}

std::string Coordinates1DIndexTester::testDefault()
{
	return Coordinates1DIndexDefaultTest().test();
}

std::string Coordinates1DIndexTester::testMinimum()
{
	return Coordinates1DIndexMinimumTest().test();
}
