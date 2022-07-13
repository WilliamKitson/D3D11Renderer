#include "SamplerTester.h"

SamplerTester::SamplerTester()
{
}

SamplerTester::~SamplerTester()
{
}

std::string SamplerTester::test()
{
	std::string output{ "" };

	output += testDefault();

	return output;
}

std::string SamplerTester::testDefault()
{
	return SamplerDefaultTest().test();
}
