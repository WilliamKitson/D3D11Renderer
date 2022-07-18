#include "OutputTester.h"

OutputTester::OutputTester()
{
}

OutputTester::~OutputTester()
{
}

std::string OutputTester::test()
{
	std::string output{ "" };

	output += testWidth();
	output += testHeight();

	return output;
}

std::string OutputTester::testWidth()
{
	return OutputWidthTest().test();
}

std::string OutputTester::testHeight()
{
	return OutputHeightTest().test();
}
