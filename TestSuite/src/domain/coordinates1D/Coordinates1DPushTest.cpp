#include "Coordinates1DPushTest.h"

Coordinates1DPushTest::Coordinates1DPushTest()
	: itterations{ 4 }, successes{ 0 }
{
}

Coordinates1DPushTest::~Coordinates1DPushTest()
{
}

std::string Coordinates1DPushTest::test()
{
	D3D11Renderer::Coordinates1D unit;

	for (int i{ 0 }; i < itterations; i++)
	{
		unit.push((float)i);
	}

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
