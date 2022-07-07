#include "Coordinates3DIndexMaximumTest.h"

Coordinates3DIndexMaximumTest::Coordinates3DIndexMaximumTest()
	: unit(), value()
{
	value[0] = 1.0f;
	unit.push(value);
}

Coordinates3DIndexMaximumTest::~Coordinates3DIndexMaximumTest()
{
}

std::string Coordinates3DIndexMaximumTest::test()
{
	unit.setIndex(1);

	if (unit.getX() == value[0])
	{
		return std::string();
	}

	return "coordinates3D index maximum test failed\n";
}
