#include "Coordinates3DEmptyTester.h"

Coordinates3DEmptyTester::Coordinates3DEmptyTester()
{
}

Coordinates3DEmptyTester::~Coordinates3DEmptyTester()
{
}

std::string Coordinates3DEmptyTester::test()
{
	std::string failures{ "" };

	failures += testX();
	failures += testY();
	failures += testZ();

	return failures;
}

std::string Coordinates3DEmptyTester::testX()
{
	return Coordinates3DEmptyXTest().test();
}

std::string Coordinates3DEmptyTester::testY()
{
	return Coordinates3DEmptyYTest().test();
}

std::string Coordinates3DEmptyTester::testZ()
{
	return Coordinates3DEmptyZTest().test();
}
