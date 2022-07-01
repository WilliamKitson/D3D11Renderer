#include "CBufferPerObjectTransformTest.h"

CBufferPerObjectTransformTest::CBufferPerObjectTransformTest()
{
}

CBufferPerObjectTransformTest::~CBufferPerObjectTransformTest()
{
}

std::string CBufferPerObjectTransformTest::test()
{
	if (success())
	{
		return std::string();
	}

	return "CBufferPerObject transform test failed\n";
}

bool CBufferPerObjectTransformTest::success()
{
	for (int i{ 0 }; i < 16; i++)
	{
		if (D3D11Renderer::CBufferPerObject().transform[i] != 1.0f)
		{
			return false;
		}
	}

	return true;
}
