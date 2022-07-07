#include "Coordinates3DCountDefaultTest.h"

Coordinates3DCountDefaultTest::Coordinates3DCountDefaultTest()
{
}

Coordinates3DCountDefaultTest::~Coordinates3DCountDefaultTest()
{
}

std::string Coordinates3DCountDefaultTest::test()
{
	if (!D3D11Renderer::Coordinates3D().getCount())
	{
		return std::string();
	}

	return "coordinates3D count default test failed\n";
}
