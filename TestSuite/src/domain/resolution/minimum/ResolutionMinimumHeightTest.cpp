#include "ResolutionMinimumHeightTest.h"

ResolutionMinimumHeightTest::ResolutionMinimumHeightTest()
{
}

ResolutionMinimumHeightTest::~ResolutionMinimumHeightTest()
{
}

std::string ResolutionMinimumHeightTest::test()
{
	D3D11Renderer::Resolution unit;

	int resolution[2]{
		0,
		0
	};

	unit.setResolution(resolution);

	if (unit.getHeight() == 540)
	{
		return std::string();
	}

	return "resolution minimum height test failed\n";
}
