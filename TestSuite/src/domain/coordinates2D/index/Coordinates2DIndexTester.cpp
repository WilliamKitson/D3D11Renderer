#include "Coordinates2DIndexTester.h"

Coordinates2DIndexTester::Coordinates2DIndexTester()
{
}

Coordinates2DIndexTester::~Coordinates2DIndexTester()
{
}

std::string Coordinates2DIndexTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testMinimum();
	failures += testMaximum();

	return failures;
}

std::string Coordinates2DIndexTester::testDefault()
{
	return Coordinates2DIndexDefaultTest().test();
}

std::string Coordinates2DIndexTester::testMinimum()
{
	return Coordinates2DIndexMinimumTest().test();
}

std::string Coordinates2DIndexTester::testMaximum()
{
	return Coordinates2DIndexMaximumTest().test();
}
