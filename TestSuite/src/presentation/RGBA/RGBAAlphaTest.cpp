#include "RGBAAlphaTest.h"

RGBAAlphaTest::RGBAAlphaTest()
{
}

RGBAAlphaTest::~RGBAAlphaTest()
{
}

std::string RGBAAlphaTest::test()
{
	if (!D3D11Renderer::RGBA().alpha)
	{
		return std::string();
	}

	return "RGBA alpha test failed\n";
}
