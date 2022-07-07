#include "Coordinates3DCountTester.h"

Coordinates3DCountTester::Coordinates3DCountTester()
{
}

Coordinates3DCountTester::~Coordinates3DCountTester()
{
}

std::string Coordinates3DCountTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testPush();
	failures += testClear();

	return failures;
}

std::string Coordinates3DCountTester::testDefault()
{
	return Coordinates3DCountDefaultTest().test();
}

std::string Coordinates3DCountTester::testPush()
{
	return Coordinates3DCountPushTest().test();
}

std::string Coordinates3DCountTester::testClear()
{
	return Coordinates3DCountClearTest().test();
}
