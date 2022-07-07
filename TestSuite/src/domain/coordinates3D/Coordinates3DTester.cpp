#include "Coordinates3DTester.h"

Coordinates3DTester::Coordinates3DTester()
{
}

Coordinates3DTester::~Coordinates3DTester()
{
}

std::string Coordinates3DTester::test()
{
	std::string failures{ "" };

	failures += testCount();
	failures += testEmpty();
	failures += testPush();
	failures += testIndex();

	return failures;
}

std::string Coordinates3DTester::testCount()
{
	return Coordinates3DCountTester().test();
}

std::string Coordinates3DTester::testEmpty()
{
	return Coordinates3DEmptyTester().test();
}

std::string Coordinates3DTester::testPush()
{
	return Coordinates3DPushTester().test();
}

std::string Coordinates3DTester::testIndex()
{
	return Coordinates3DIndexTester().test();
}
