#include "ResolutionParameterWidthTest.h"

ResolutionParameterWidthTest::ResolutionParameterWidthTest()
	: width{ 1000 }
{
}

ResolutionParameterWidthTest::~ResolutionParameterWidthTest()
{
}

std::string ResolutionParameterWidthTest::test()
{
	windowsPlatform::Resolution unit;

	unit.setResolution(width, 0);

	if (unit.getWidth() == width)
	{
		return std::string();
	}

	return "resolution parameter width test failed\n";
}
