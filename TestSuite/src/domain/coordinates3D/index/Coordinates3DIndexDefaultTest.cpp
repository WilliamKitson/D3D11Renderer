#include "Coordinates3DIndexDefaultTest.h"

Coordinates3DIndexDefaultTest::Coordinates3DIndexDefaultTest()
	: unit(), value()
{
	value[0] = 1.0f;
	unit.push(value);
}

Coordinates3DIndexDefaultTest::~Coordinates3DIndexDefaultTest()
{
}

std::string Coordinates3DIndexDefaultTest::test()
{
	if (unit.getX() == value[0])
	{
		return std::string();
	}

	return "coordinates3D index default test failed\n";
}
