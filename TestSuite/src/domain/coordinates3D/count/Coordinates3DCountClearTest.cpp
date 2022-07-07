#include "Coordinates3DCountClearTest.h"

Coordinates3DCountClearTest::Coordinates3DCountClearTest()
{
}

Coordinates3DCountClearTest::~Coordinates3DCountClearTest()
{
}

std::string Coordinates3DCountClearTest::test()
{
	float value[3];

	D3D11Renderer::Coordinates3D unit;

	unit.push(value);
	unit.clear();

	if (!unit.getCount())
	{
		return std::string();
	}

	return "coordinates3D count clear test failed\n";
}
