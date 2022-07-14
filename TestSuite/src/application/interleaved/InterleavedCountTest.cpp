#include "InterleavedCountTest.h"

InterleavedCountTest::InterleavedCountTest()
	: itterations{ 4 }, successes{ 0 }
{
}

InterleavedCountTest::~InterleavedCountTest()
{
}

std::string InterleavedCountTest::test()
{
	D3D11Renderer::Interleaved unit;

	for (int i{ 0 }; i < itterations; i++)
	{
		float vertex[] = {
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			0.0f,
			0.0f
		};

		unit.push(vertex);
		successes += unit.getCount() == i + 1;
	}

	if (successes == itterations)
	{
		return std::string();
	}

	return "interleaved count test failed\n";
}
