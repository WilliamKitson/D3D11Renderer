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

	return output;
}

std::string OutputTester::testWidth()
{
	return OutputWidthTest().test();
}
