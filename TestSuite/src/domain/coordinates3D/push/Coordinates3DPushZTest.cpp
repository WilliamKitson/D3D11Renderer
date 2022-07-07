#include "Coordinates3DPushZTest.h"

Coordinates3DPushZTest::Coordinates3DPushZTest()
	: unit(), itterations{ 4 }
{
	initialise();
}

Coordinates3DPushZTest::~Coordinates3DPushZTest()
{
}

std::string Coordinates3DPushZTest::test()
{
	if (successes() == itterations)
	{
		return std::string();
	}

	return "coordinates3D push z test failed\n";
}

void Coordinates3DPushZTest::initialise()
{
	float value[3];

	for (int i{ 0 }; i < itterations; i++)
	{
		value[2] = float(i);
		unit.push(value);
	}
}

int Coordinates3DPushZTest::successes()
{
	int value = 0;

	for (int i{ 0 }; i < itterations; i++)
	{
		unit.setIndex(i);
		value += unit.getZ() == float(i);
	}

	return value;
}
