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
	output += testReload();
	output += testInvalid();

	return output;
}

std::string SamplerTester::testDefault()
{
	return SamplerDefaultTest().test();
}

std::string SamplerTester::testReload()
{
	return SamplersReloadTest().test();
}

std::string SamplerTester::testInvalid()
{
	return SamplerInvalidTester().test();
}
