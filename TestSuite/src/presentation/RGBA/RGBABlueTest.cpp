#include "RGBABlueTest.h"

RGBABlueTest::RGBABlueTest()
{
}

RGBABlueTest::~RGBABlueTest()
{
}

std::string RGBABlueTest::test()
{
	if (!D3D11Renderer::RGBA().blue)
	{
		return std::string();
	}

	return "RGBA blue test failed\n";
}
