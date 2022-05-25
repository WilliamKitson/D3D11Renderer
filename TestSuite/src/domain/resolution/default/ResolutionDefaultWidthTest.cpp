#include "ResolutionDefaultWidthTest.h"

ResolutionDefaultWidthTest::ResolutionDefaultWidthTest()
{
}

ResolutionDefaultWidthTest::~ResolutionDefaultWidthTest()
{
}

std::string ResolutionDefaultWidthTest::test()
{
	if (D3D11Renderer::Resolution().getWidth() == 960)
	{
		return std::string();
	}

	return "resolution default width test failed\n";
}
