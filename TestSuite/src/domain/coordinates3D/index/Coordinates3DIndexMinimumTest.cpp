#include "Coordinates3DIndexMinimumTest.h"

Coordinates3DIndexMinimumTest::Coordinates3DIndexMinimumTest()
	: unit(), value()
{
	value[0] = 1.0f;
	unit.push(value);
}

Coordinates3DIndexMinimumTest::~Coordinates3DIndexMinimumTest()
{
}

std::string Coordinates3DIndexMinimumTest::test()
{
	unit.setIndex(-1);

	if (unit.getX() == value[0])
	{
		return std::string();
	}

	return "coordinates3D index minimum test failed\n";
}
