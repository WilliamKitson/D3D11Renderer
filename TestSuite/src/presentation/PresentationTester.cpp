#include "PresentationTester.h"

PresentationTester::PresentationTester()
{
}

PresentationTester::~PresentationTester()
{
}

std::string PresentationTester::test()
{
	std::string failures{ "" };

	failures += testCamera();
	failures += testRGB();

	return failures;
}

std::string PresentationTester::testCamera()
{
	return CameraTester().test();
}

std::string PresentationTester::testRGB()
{
	return RGBTester().test();
}
