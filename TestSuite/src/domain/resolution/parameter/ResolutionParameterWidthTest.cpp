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
	D3D11Renderer::Resolution unit;

	int resolution[2]{
		width,
		0
	};

	unit.setResolution(resolution);

	if (unit.getWidth() == width)
	{
		return std::string();
	}

	return "resolution parameter width test failed\n";
}
