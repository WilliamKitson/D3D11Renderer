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
	output += testPush();

	return output;
}

std::string Coordinates1DCountTester::testDefault()
{
	return Coordinates1DCountDefaultTest().test();
}

std::string Coordinates1DCountTester::testPush()
{
	return Coordinates1DCountPushTest().test();
}
