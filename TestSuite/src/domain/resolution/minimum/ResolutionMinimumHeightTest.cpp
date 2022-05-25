#include "ResolutionMinimumHeightTest.h"

ResolutionMinimumHeightTest::ResolutionMinimumHeightTest()
{
}

ResolutionMinimumHeightTest::~ResolutionMinimumHeightTest()
{
}

std::string ResolutionMinimumHeightTest::test()
{
	windowsPlatform::Resolution unit;

	unit.setResolution(0, 0);

	if (unit.getHeight() == 540)
	{
		return std::string();
	}

	return "resolution minimum height test failed\n";
}
