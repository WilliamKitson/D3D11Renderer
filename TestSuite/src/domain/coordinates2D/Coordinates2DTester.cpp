#include "Coordinates2DTester.h"

Coordinates2DTester::Coordinates2DTester()
{
}

Coordinates2DTester::~Coordinates2DTester()
{
}

std::string Coordinates2DTester::test()
{
	std::string failures{ "" };

	failures += testCount();
	failures += testEmpty();
	failures += testPush();
	failures += testIndex();

	return failures;
}

std::string Coordinates2DTester::testCount()
{
	return Coordinates2DCountTester().test();
}

std::string Coordinates2DTester::testEmpty()
{
	return Coordinates2DEmptyTester().test();
}

std::string Coordinates2DTester::testPush()
{
	return Coordinates2DPushTester().test();
}

std::string Coordinates2DTester::testIndex()
{
	return Coordinates2DIndexTester().test();
}
