#include "Coordinates2DEmptyXTest.h"

Coordinates2DEmptyXTest::Coordinates2DEmptyXTest()
{
}

Coordinates2DEmptyXTest::~Coordinates2DEmptyXTest()
{
}

std::string Coordinates2DEmptyXTest::test()
{
	if (!D3D11Renderer::Coordinates2D().getX())
	{
		return std::string();
	}

	return "coordinates2D empty x test failed\n";
}
