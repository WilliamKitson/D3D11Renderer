#include "Coordinates3DCountPushTest.h"

Coordinates3DCountPushTest::Coordinates3DCountPushTest()
	: unit(), itterations{ 4 }
{
	initialise();
}

Coordinates3DCountPushTest::~Coordinates3DCountPushTest()
{
}

std::string Coordinates3DCountPushTest::test()
{
	if (unit.getCount() == itterations)
	{
		return std::string();
	}

	return "coordinates3D count push test failed\n";
}

void Coordinates3DCountPushTest::initialise()
{
	float value[3];

	for (int i{ 0 }; i < itterations; i++)
	{
		unit.push(value);
	}
}
