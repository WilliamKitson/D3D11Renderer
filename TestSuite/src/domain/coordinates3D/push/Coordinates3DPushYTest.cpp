#include "Coordinates3DPushYTest.h"

Coordinates3DPushYTest::Coordinates3DPushYTest()
	: unit(), itterations{ 4 }
{
	initialise();
}

Coordinates3DPushYTest::~Coordinates3DPushYTest()
{
}

std::string Coordinates3DPushYTest::test()
{
	if (successes() == itterations)
	{
		return std::string();
	}

	return "coordinates3D push y test failed\n";
}

void Coordinates3DPushYTest::initialise()
{
	float value[3];

	for (int i{ 0 }; i < itterations; i++)
	{
		value[1] = float(i);
		unit.push(value);
	}
}

int Coordinates3DPushYTest::successes()
{
	int value = 0;

	for (int i{ 0 }; i < itterations; i++)
	{
		unit.setIndex(i);
		value += unit.getY() == float(i);
	}

	return value;
}
