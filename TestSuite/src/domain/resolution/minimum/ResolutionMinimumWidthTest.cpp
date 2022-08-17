#include "ResolutionMinimumWidthTest.h"

ResolutionMinimumWidthTest::ResolutionMinimumWidthTest()
	: unit()
{
	initialise();
}

ResolutionMinimumWidthTest::~ResolutionMinimumWidthTest()
{
}

std::string ResolutionMinimumWidthTest::test()
{
	if (unit.getWidth() == 960)
	{
		return std::string();
	}

	return "resolution minimum width test failed\n";
}

void ResolutionMinimumWidthTest::initialise()
{
	int resolution[2]{
		0,
		0
	};

	unit.setResolution(resolution);
}
