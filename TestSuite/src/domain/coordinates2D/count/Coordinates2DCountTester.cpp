#include "Coordinates2DCountTester.h"

Coordinates2DCountTester::Coordinates2DCountTester()
{
}

Coordinates2DCountTester::~Coordinates2DCountTester()
{
}

std::string Coordinates2DCountTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testPush();
	failures += testClear();

	return failures;
}

std::string Coordinates2DCountTester::testDefault()
{
	return Coordinates2DCountDefaultTest().test();
}

std::string Coordinates2DCountTester::testPush()
{
	return Coordinates2DCountPushTest().test();
}

std::string Coordinates2DCountTester::testClear()
{
	return Coordinates2DCountClearTest().test();
}
