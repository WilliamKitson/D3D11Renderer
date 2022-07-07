#include "Coordinates3DEmptyXTest.h"

Coordinates3DEmptyXTest::Coordinates3DEmptyXTest()
{
}

Coordinates3DEmptyXTest::~Coordinates3DEmptyXTest()
{
}

std::string Coordinates3DEmptyXTest::test()
{
	if (!D3D11Renderer::Coordinates3D().getX())
	{
		return std::string();
	}

	return "coordinates3D empty x test failed\n";
}
