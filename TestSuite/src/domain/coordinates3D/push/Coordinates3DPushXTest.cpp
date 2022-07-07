#include "Coordinates3DPushXTest.h"

Coordinates3DPushXTest::Coordinates3DPushXTest()
	: unit(), itterations{ 4 }
{
	initialise();
}

Coordinates3DPushXTest::~Coordinates3DPushXTest()
{
}

std::string Coordinates3DPushXTest::test()
{
	if (successes() == itterations)
	{
		return std::string();
	}

	return "coordinates3D push x test failed\n";
}

void Coordinates3DPushXTest::initialise()
{
	float value[3];

	for (int i{ 0 }; i < itterations; i++)
	{
		value[0] = float(i);
		unit.push(value);
	}
}

int Coordinates3DPushXTest::successes()
{
	int value = 0;

	for (int i{ 0 }; i < itterations; i++)
	{
		unit.setIndex(i);
		value += unit.getX() == float(i);
	}

	return value;
}
