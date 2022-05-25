#include "RGBARedTest.h"

RGBARedTest::RGBARedTest()
{
}

RGBARedTest::~RGBARedTest()
{
}

std::string RGBARedTest::test()
{
	if (!D3D11Renderer::RGBA().red)
	{
		return std::string();
	}

	return "RGBA red test failed\n";
}
