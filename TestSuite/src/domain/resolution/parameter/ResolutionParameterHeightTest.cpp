#include "ResolutionParameterHeightTest.h"

ResolutionParameterHeightTest::ResolutionParameterHeightTest()
	: height{ 1000 }
{
}

ResolutionParameterHeightTest::~ResolutionParameterHeightTest()
{
}

std::string ResolutionParameterHeightTest::test()
{
	D3D11Renderer::Resolution unit;

	int resolution[2]{
		0,
		height
	};

	unit.setResolution(resolution);

	if (unit.getHeight() == height)
	{
		return std::string();
	}

	return "resolution parameter height test failed\n";
}
