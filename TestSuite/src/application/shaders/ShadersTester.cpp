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

	return output;
}

std::string ShadersTester::testLoad()
{
	return ShadersLoadTester().test();
}
