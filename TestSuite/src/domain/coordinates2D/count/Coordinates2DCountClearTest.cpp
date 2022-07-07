#include "Coordinates2DCountClearTest.h"

Coordinates2DCountClearTest::Coordinates2DCountClearTest()
{
}

Coordinates2DCountClearTest::~Coordinates2DCountClearTest()
{
}

std::string Coordinates2DCountClearTest::test()
{
	float value[2];

	D3D11Renderer::Coordinates2D unit;

	unit.push(value);
	unit.clear();

	if (!unit.getCount())
	{
		return std::string();
	}

	return "coordinates2D count clear test failed\n";
}
