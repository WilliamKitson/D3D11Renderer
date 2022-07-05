#include "CBufferPerSceneWorldViewProjectionTest.h"

CBufferPerSceneWorldViewProjectionTest::CBufferPerSceneWorldViewProjectionTest()
{
}

CBufferPerSceneWorldViewProjectionTest::~CBufferPerSceneWorldViewProjectionTest()
{
}

std::string CBufferPerSceneWorldViewProjectionTest::test()
{
	if (success())
	{
		return std::string();
	}

	return "CBuffer per scene world view projection test failed\n";
}

bool CBufferPerSceneWorldViewProjectionTest::success()
{
	for (int i{ 0 }; i < 16; i++)
	{
		if (D3D11Renderer::CBufferPerScene().worldViewProjection[i] != 1.0f)
		{
			return false;
		}
	}

	return true;
}
