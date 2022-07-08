#include "Coordinates1DEmptyTest.h"

Coordinates1DEmptyTest::Coordinates1DEmptyTest()
{
}

Coordinates1DEmptyTest::~Coordinates1DEmptyTest()
{
}

std::string Coordinates1DEmptyTest::test()
{
	if (!D3D11Renderer::Coordinates1D().getCoordinate())
	{
		return std::string();
	}

	return "coordinates 1D empty test failed\n";
}
