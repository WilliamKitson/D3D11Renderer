#include "CBufferPerSceneAmbienceTest.h"

CBufferPerSceneAmbienceTest::CBufferPerSceneAmbienceTest()
{
}

CBufferPerSceneAmbienceTest::~CBufferPerSceneAmbienceTest()
{
}

std::string CBufferPerSceneAmbienceTest::test()
{
	if (success())
	{
		return std::string();
	}

	return "CBuffer per scene ambience test failed\n";
}

bool CBufferPerSceneAmbienceTest::success()
{
	for (int i{ 0 }; i < 4; i++)
	{
		if (D3D11Renderer::CBufferPerScene().ambience[i] != 1.0f)
		{
			return false;
		}
	}

	return true;
}
