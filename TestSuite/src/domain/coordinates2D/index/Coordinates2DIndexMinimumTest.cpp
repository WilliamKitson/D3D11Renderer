#include "Coordinates2DIndexMinimumTest.h"

Coordinates2DIndexMinimumTest::Coordinates2DIndexMinimumTest()
	: unit(), value()
{
	value[0] = 1.0f;
	unit.push(value);
}

Coordinates2DIndexMinimumTest::~Coordinates2DIndexMinimumTest()
{
}

std::string Coordinates2DIndexMinimumTest::test()
{
	unit.setIndex(-1);

	if (unit.getX() == value[0])
	{
		return std::string();
	}

	return "coordinates2D index minimum test failed\n";
}
