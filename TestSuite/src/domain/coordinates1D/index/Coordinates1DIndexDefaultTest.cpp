#include "Coordinates1DIndexDefaultTest.h"

Coordinates1DIndexDefaultTest::Coordinates1DIndexDefaultTest()
{
}

Coordinates1DIndexDefaultTest::~Coordinates1DIndexDefaultTest()
{
}

std::string Coordinates1DIndexDefaultTest::test()
{
	float coordinate = 1.0f;

	D3D11Renderer::Coordinates1D unit;
	unit.push(coordinate);

	if (unit.getCoordinate() == coordinate)
	{
		return std::string();
	}

	return "coordinates 1D index default test failed\n";
}
