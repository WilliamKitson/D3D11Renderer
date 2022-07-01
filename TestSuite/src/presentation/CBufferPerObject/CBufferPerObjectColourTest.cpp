#include "CBufferPerObjectColourTest.h"

CBufferPerObjectColourTest::CBufferPerObjectColourTest()
{
}

CBufferPerObjectColourTest::~CBufferPerObjectColourTest()
{
}

std::string CBufferPerObjectColourTest::test()
{
	int itterations = 4;
	int successes = 0;

	for (int i{ 0 }; i < itterations; i++)
	{
		successes += D3D11Renderer::CBufferPerObject().colour[i] == 1.0f;
	}

	if (successes == itterations)
	{
		return std::string();
	}

	return "CBuffer per object colour test failed\n";
}
