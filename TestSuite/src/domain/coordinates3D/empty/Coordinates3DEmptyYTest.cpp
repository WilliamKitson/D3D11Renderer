#include "Coordinates3DEmptyYTest.h"

Coordinates3DEmptyYTest::Coordinates3DEmptyYTest()
{
}

Coordinates3DEmptyYTest::~Coordinates3DEmptyYTest()
{
}

std::string Coordinates3DEmptyYTest::test()
{
	if (!D3D11Renderer::Coordinates3D().getY())
	{
		return std::string();
	}

	return "coordinates3D empty y test failed\n";
}
