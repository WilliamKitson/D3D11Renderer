#include "Coordinates3DEmptyZTest.h"

Coordinates3DEmptyZTest::Coordinates3DEmptyZTest()
{
}

Coordinates3DEmptyZTest::~Coordinates3DEmptyZTest()
{
}

std::string Coordinates3DEmptyZTest::test()
{
	if (!D3D11Renderer::Coordinates3D().getZ())
	{
		return std::string();
	}

	return "coordinates3D empty z test failed\n";
}
