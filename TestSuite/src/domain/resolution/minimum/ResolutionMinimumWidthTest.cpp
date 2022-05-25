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

	int resolution[2]{
		0,
		0
	};

	unit.setResolution(resolution);

	if (unit.getWidth() == 960)
	{
		return std::string();
	}

	return "resolution minimum width test failed\n";
}
