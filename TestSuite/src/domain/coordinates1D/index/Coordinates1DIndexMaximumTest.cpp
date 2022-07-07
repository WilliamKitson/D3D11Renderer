#include "Coordinates1DIndexMaximumTest.h"

Coordiantes1DIndexMaximumTest::Coordiantes1DIndexMaximumTest()
	: coordinate{ 1.0f }
{
}

Coordiantes1DIndexMaximumTest::~Coordiantes1DIndexMaximumTest()
{
}

std::string Coordiantes1DIndexMaximumTest::test()
{
	D3D11Renderer::Coordinates1D unit;
	unit.push(coordinate);

	unit.setIndex(1);

	if (unit.getCoordinate() == coordinate)
	{
		return std::string();
	}

	return "coordinates 1D index maximum test failed\n";
}
