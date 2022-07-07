#include "Coordinates1DPushTest.h"

Coordinates1DPushTest::Coordinates1DPushTest()
	: unit(), itterations{ 4 }, successes{ 0 }
{
}

Coordinates1DPushTest::~Coordinates1DPushTest()
{
}

std::string Coordinates1DPushTest::test()
{
	initialise();

	for (int i{ 0 }; i < itterations; i++)
	{
		unit.setIndex(i);
		successes += unit.getCoordinate() == (float)i;
	}

	if (successes == itterations)
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
