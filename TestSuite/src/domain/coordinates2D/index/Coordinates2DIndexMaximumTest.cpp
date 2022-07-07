#include "Coordinates2DIndexMaximumTest.h"

Coordinates2DIndexMaximumTest::Coordinates2DIndexMaximumTest()
	: unit(), value()
{
	value[0] = 1.0f;
	unit.push(value);
}

Coordinates2DIndexMaximumTest::~Coordinates2DIndexMaximumTest()
{
}

std::string Coordinates2DIndexMaximumTest::test()
{
	unit.setIndex(1);

	if (unit.getX() == value[0])
	{
		return std::string();
	}

	return "coordinates2D index maximum test failed\n";
}
