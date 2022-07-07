#include "Coordinates1DPushTest.h"

Coordinates1DPushTest::Coordinates1DPushTest()
	: unit(), itterations{ 4 }
{
}

Coordinates1DPushTest::~Coordinates1DPushTest()
{
}

std::string Coordinates1DPushTest::test()
{
	initialise();

	if (successes() == itterations)
	{
		return std::string();
	}

	return "coordinates 1D push test failed\n";
}

void Coordinates1DPushTest::initialise()
{
	for (int i{ 0 }; i < itterations; i++)
	{
		unit.push((float)i);
	}
}

int Coordinates1DPushTest::successes()
{
	int output = 0;

	for (int i{ 0 }; i < itterations; i++)
	{
		unit.setIndex(i);
		output += unit.getCoordinate() == (float)i;
	}

	return output;
}
