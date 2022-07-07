#include "Coordinates1DCountDefaultTest.h"

Coordinates1DCountDefaultTest::Coordinates1DCountDefaultTest()
{
}

Coordinates1DCountDefaultTest::~Coordinates1DCountDefaultTest()
{
}

std::string Coordinates1DCountDefaultTest::test()
{
	if (!D3D11Renderer::Coordinates1D().getCount())
	{
		return std::string();
	}

	return "coordinates 1D count default test failed\n";
}
