#include "PresentationTester.h"

PresentationTester::PresentationTester()
{
}

PresentationTester::~PresentationTester()
{
}

std::string PresentationTester::test()
{
	std::string output{ "" };

	output += testOutput();
	output += testCamera();
	output += testRGB();

	return output;
}

std::string PresentationTester::testOutput()
{
	return OutputTester().test();
}

std::string PresentationTester::testCamera()
{
	return CameraTester().test();
}

std::string PresentationTester::testRGB()
{
	return RGBTester().test();
}
