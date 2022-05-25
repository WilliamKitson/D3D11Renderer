#include "RGBGreenTest.h"

RGBGreenTest::RGBGreenTest()
{
}

RGBGreenTest::~RGBGreenTest()
{
}

std::string RGBGreenTest::test()
{
	if (!D3D11Renderer::RGB().green)
	{
		return std::string();
	}

	return "RGB green test failed\n";
}
