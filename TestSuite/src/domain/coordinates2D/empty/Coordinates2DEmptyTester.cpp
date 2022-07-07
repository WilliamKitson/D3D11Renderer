#include "Coordinates2DEmptyTester.h"

Coordinates2DEmptyTester::Coordinates2DEmptyTester()
{
}

Coordinates2DEmptyTester::~Coordinates2DEmptyTester()
{
}

std::string Coordinates2DEmptyTester::test()
{
	std::string failures{ "" };

	failures += testX();
	failures += testY();

	return failures;
}

std::string Coordinates2DEmptyTester::testX()
{
	return Coordinates2DEmptyXTest().test();
}

std::string Coordinates2DEmptyTester::testY()
{
	return Coordinates2DEmptyYTest().test();
}
