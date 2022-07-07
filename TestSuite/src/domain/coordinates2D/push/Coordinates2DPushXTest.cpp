#include "Coordinates2DPushXTest.h"

Coordinates2DPushXTest::Coordinates2DPushXTest()
	: unit(), itterations{ 4 }
{
	initialise();
}

Coordinates2DPushXTest::~Coordinates2DPushXTest()
{
}

std::string Coordinates2DPushXTest::test()
{
	if (successes() == itterations)
	{
		return std::string();
	}

	return "coordinates2D push x test failed\n";
}

void Coordinates2DPushXTest::initialise()
{
	float value[2];

	for (int i{ 0 }; i < itterations; i++)
	{
		value[0] = (float)i;
		unit.push(value);
	}
}

int Coordinates2DPushXTest::successes()
{
	int value = 0;

	for (int i{ 0 }; i < itterations; i++)
	{
		unit.setIndex(i);
		value += unit.getX() == (float)i;
	}

	return value;
}
