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

	return failures;
}

std::string PresentationTester::testCamera()
{
	return CameraTester().test();
}
