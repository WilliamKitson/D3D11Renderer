#include "Coordinates3DPushTester.h"

Coordinates3DPushTester::Coordinates3DPushTester()
{
}

Coordinates3DPushTester::~Coordinates3DPushTester()
{
}

std::string Coordinates3DPushTester::test()
{
	std::string failures{ "" };

	failures += testX();
	failures += testY();
	failures += testZ();

	return failures;
}

std::string Coordinates3DPushTester::testX()
{
	return Coordinates3DPushXTest().test();
}

std::string Coordinates3DPushTester::testY()
{
	return Coordinates3DPushYTest().test();
}

std::string Coordinates3DPushTester::testZ()
{
	return Coordinates3DPushZTest().test();
}
