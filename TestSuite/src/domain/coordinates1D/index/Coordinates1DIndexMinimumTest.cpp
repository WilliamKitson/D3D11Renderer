#include "Coordinates1DIndexMinimumTest.h"

Coordinates1DIndexMinimumTest::Coordinates1DIndexMinimumTest()
	: coordinate{ 1.0f }
{
}

Coordinates1DIndexMinimumTest::~Coordinates1DIndexMinimumTest()
{
}

std::string Coordinates1DIndexMinimumTest::test()
{
	D3D11Renderer::Coordinates1D unit;
	unit.push(coordinate);

	unit.setIndex(-1);

	if (unit.getCoordinate() == coordinate)
	{
		return std::string();
	}

	return "coordinates 1D index minimum test failed\n";
}
