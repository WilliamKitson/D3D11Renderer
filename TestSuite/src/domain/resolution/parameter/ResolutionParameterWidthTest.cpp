#include "ResolutionParameterWidthTest.h"

ResolutionParameterWidthTest::ResolutionParameterWidthTest()
	: unit(), width{ 1000 }
{
	initialise();
}

ResolutionParameterWidthTest::~ResolutionParameterWidthTest()
{
}

std::string ResolutionParameterWidthTest::test()
{
	if (unit.getWidth() == width)
	{
		return std::string();
	}

	return "resolution parameter width test failed\n";
}

void ResolutionParameterWidthTest::initialise()
{
	int resolution[2]{
		width,
		0
	};

	unit.setResolution(resolution);
}
