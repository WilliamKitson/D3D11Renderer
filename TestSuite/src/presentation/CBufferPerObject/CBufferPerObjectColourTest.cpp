#include "CBufferPerObjectColourTest.h"

CBufferPerObjectColourTest::CBufferPerObjectColourTest()
{
}

CBufferPerObjectColourTest::~CBufferPerObjectColourTest()
{
}

std::string CBufferPerObjectColourTest::test()
{
	if (success())
	{
		return std::string();
	}

	return "CBuffer per object colour test failed\n";
}

bool CBufferPerObjectColourTest::success()
{
	for (int i{ 0 }; i < 4; i++)
	{
		if (D3D11Renderer::CBufferPerObject().colour[i] != 1.0f)
		{
			return false;
		}
	}

	return true;
}
