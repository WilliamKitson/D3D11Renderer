#include "RGBAGreenTest.h"

RGBAGreenTest::RGBAGreenTest()
{
}

RGBAGreenTest::~RGBAGreenTest()
{
}

std::string RGBAGreenTest::test()
{
	if (!D3D11Renderer::RGBA().green)
	{
		return std::string();
	}

	return "RGBA green test failed\n";
}
