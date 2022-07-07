#include "Coordinates2DPushYTest.h"

Coordinates2DPushYTest::Coordinates2DPushYTest()
	: unit(), itterations{ 4 }
{
	initialise();
}

Coordinates2DPushYTest::~Coordinates2DPushYTest()
{
}

std::string Coordinates2DPushYTest::test()
{
	if (successes() == itterations)
	{
		return std::string();
	}

	return "coordinates2D push y test failed\n";
}

void Coordinates2DPushYTest::initialise()
{
	float value[2];

	for (int i{ 0 }; i < itterations; i++)
	{
		value[1] = (float)i;
		unit.push(value);
	}
}

int Coordinates2DPushYTest::successes()
{
	int value = 0;

	for (int i{ 0 }; i < itterations; i++)
	{
		unit.setIndex(i);
		value += unit.getY() == (float)i;
	}

	return value;
}
