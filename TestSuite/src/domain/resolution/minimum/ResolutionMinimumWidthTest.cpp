#include "ResolutionMinimumWidthTest.h"

ResolutionMinimumWidthTest::ResolutionMinimumWidthTest()
{
}

ResolutionMinimumWidthTest::~ResolutionMinimumWidthTest()
{
}

std::string ResolutionMinimumWidthTest::test()
{
	D3D11Renderer::Resolution unit;

	unit.setResolution(0, 0);

	if (unit.getWidth() == 960)
	{
		return std::string();
	}

	return "resolution minimum width test failed\n";
}
