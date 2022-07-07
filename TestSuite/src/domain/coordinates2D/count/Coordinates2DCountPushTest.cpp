#include "Coordinates2DCountPushTest.h"

Coordinates2DCountPushTest::Coordinates2DCountPushTest()
	: unit(), itterations{ 4 }
{
	initialise();
}

Coordinates2DCountPushTest::~Coordinates2DCountPushTest()
{
}

std::string Coordinates2DCountPushTest::test()
{
	if (unit.getCount() == itterations)
	{
		return std::string();
	}

	return "coordinates2D count push test failed\n";
}

void Coordinates2DCountPushTest::initialise()
{
	float value[2];

	for (int i{ 0 }; i < itterations; i++)
	{
		unit.push(value);
	}
}
