#include "Coordinates2DIndexDefaultTest.h"

Coordinates2DIndexDefaultTest::Coordinates2DIndexDefaultTest()
	: unit(), value()
{
	value[0] = 1.0f;
	unit.push(value);
}

Coordinates2DIndexDefaultTest::~Coordinates2DIndexDefaultTest()
{
}

std::string Coordinates2DIndexDefaultTest::test()
{
	if (unit.getX() == value[0])
	{
		return std::string();
	}

	return "coordinates2D index default test failed\n";
}
