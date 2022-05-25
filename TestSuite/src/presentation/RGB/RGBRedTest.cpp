#include "RGBRedTest.h"

RGBRedTest::RGBRedTest()
{
}

RGBRedTest::~RGBRedTest()
{
}

std::string RGBRedTest::test()
{
	if (!D3D11Renderer::RGB().red)
	{
		return std::string();
	}

	return "RGB red test failed\n";
}
