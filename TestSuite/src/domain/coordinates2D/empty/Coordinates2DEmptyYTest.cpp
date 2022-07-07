#include "Coordinates2DEmptyYTest.h"

Coordinates2DEmptyYTest::Coordinates2DEmptyYTest()
{
}

Coordinates2DEmptyYTest::~Coordinates2DEmptyYTest()
{
}

std::string Coordinates2DEmptyYTest::test()
{
	if (!D3D11Renderer::Coordinates2D().getY())
	{
		return std::string();
	}

	return "coordinates2D empty y test failed\n";
}
