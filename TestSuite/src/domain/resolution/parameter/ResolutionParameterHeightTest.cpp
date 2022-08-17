#include "ResolutionParameterHeightTest.h"

ResolutionParameterHeightTest::ResolutionParameterHeightTest()
	: unit(), height{ 1000 }
{
	initialise();
}

ResolutionParameterHeightTest::~ResolutionParameterHeightTest()
{
}

std::string ResolutionParameterHeightTest::test()
{
	if (unit.getHeight() == height)
	{
		return std::string();
	}

	return "resolution parameter height test failed\n";
}

void ResolutionParameterHeightTest::initialise()
{
	int resolution[2]{
		0,
		height
	};

	unit.setResolution(resolution);
}
