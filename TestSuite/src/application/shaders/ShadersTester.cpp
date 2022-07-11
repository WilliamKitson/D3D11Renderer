#include "ShadersTester.h"

ShadersTester::ShadersTester()
{
}

ShadersTester::~ShadersTester()
{
}

std::string ShadersTester::test()
{
	std::string output{ "" };

	output += testLoad();
	output += testInvalid();

	return output;
}

std::string ShadersTester::testLoad()
{
	return ShadersLoadTester().test();
}

std::string ShadersTester::testInvalid()
{
	return ShadersInvalidTester().test();
}
