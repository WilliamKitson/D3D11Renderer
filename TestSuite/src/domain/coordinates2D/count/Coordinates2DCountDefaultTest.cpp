#include "Coordinates2DCountDefaultTest.h"

Coordinates2DCountDefaultTest::Coordinates2DCountDefaultTest()
{
}

Coordinates2DCountDefaultTest::~Coordinates2DCountDefaultTest()
{
}

std::string Coordinates2DCountDefaultTest::test()
{
	if (!D3D11Renderer::Coordinates2D().getCount())
	{
		return std::string();
	}

	return "coordinates2D count default test failed\n";
}
