#include "RGBBlueTest.h"

RGBBlueTest::RGBBlueTest()
{
}

RGBBlueTest::~RGBBlueTest()
{
}

std::string RGBBlueTest::test()
{
	if (!D3D11Renderer::RGB().blue)
	{
		return std::string();
	}

	return "RGB blue test failed\n";
}
