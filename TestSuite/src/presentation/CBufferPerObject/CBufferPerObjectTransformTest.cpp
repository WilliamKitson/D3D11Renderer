#include "CBufferPerObjectTransformTest.h"

CBufferPerObjectTransformTest::CBufferPerObjectTransformTest()
{
}

CBufferPerObjectTransformTest::~CBufferPerObjectTransformTest()
{
}

std::string CBufferPerObjectTransformTest::test()
{
	int itterations = 16;
	int successes = 0;

	for (int i{ 0 }; i < itterations; i++)
	{
		successes += D3D11Renderer::CBufferPerObject().transform[i] == 1.0f;
	}

	if (successes == itterations)
	{
		return std::string();
	}

	return "CBufferPerObject transform test failed\n";
}
