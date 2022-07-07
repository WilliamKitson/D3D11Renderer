#include "Coordinates1DCountPushTest.h"

Coordinates1DCountPushTest::Coordinates1DCountPushTest()
	: unit(), itterations{ 4 }
{
}

Coordinates1DCountPushTest::~Coordinates1DCountPushTest()
{
}

std::string Coordinates1DCountPushTest::test()
{
	initialise();

	if (unit.getCount() == itterations)
	{
		return std::string();
	}

	return "coordinates 1D count push test failed\n";
}

void Coordinates1DCountPushTest::initialise()
{
	for (int i{ 0 }; i < itterations; i++)
	{
		unit.push(0.0f);
	}
}
