#include "ResolutionMinimumHeightTest.h"

ResolutionMinimumHeightTest::ResolutionMinimumHeightTest()
	: unit()
{
	initialise();
}

ResolutionMinimumHeightTest::~ResolutionMinimumHeightTest()
{
}

std::string ResolutionMinimumHeightTest::test()
{
	if (unit.getHeight() == 540)
	{
		return std::string();
	}

	return "resolution minimum height test failed\n";
}

void ResolutionMinimumHeightTest::initialise()
{
	int resolution[2]{
		0,
		0
	};

	unit.setResolution(resolution);
}
