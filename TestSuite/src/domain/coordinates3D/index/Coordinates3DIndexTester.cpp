#include "Coordinates3DIndexTester.h"

Coordinates3DIndexTester::Coordinates3DIndexTester()
{
}

Coordinates3DIndexTester::~Coordinates3DIndexTester()
{
}

std::string Coordinates3DIndexTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testMinimum();
	failures += testMaximum();

	return failures;
}

std::string Coordinates3DIndexTester::testDefault()
{
	return Coordinates3DIndexDefaultTest().test();
}

std::string Coordinates3DIndexTester::testMinimum()
{
	return Coordinates3DIndexMinimumTest().test();
}

std::string Coordinates3DIndexTester::testMaximum()
{
	return Coordinates3DIndexMaximumTest().test();
}
