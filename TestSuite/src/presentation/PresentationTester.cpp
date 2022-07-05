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
	failures += testRGBA();

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

std::string PresentationTester::testRGBA()
{
	return RGBATester().test();
}
