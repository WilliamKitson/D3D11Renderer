#include "Coordinates2DPushTester.h"

Coordinates2DPushTester::Coordinates2DPushTester()
{
}

Coordinates2DPushTester::~Coordinates2DPushTester()
{
}

std::string Coordinates2DPushTester::test()
{
	std::string failures{ "" };

	failures += testX();
	failures += testY();

	return failures;
}

std::string Coordinates2DPushTester::testX()
{
	return Coordinates2DPushXTest().test();
}

std::string Coordinates2DPushTester::testY()
{
	return Coordinates2DPushYTest().test();
}
