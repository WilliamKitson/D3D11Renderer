#include "CBufferPerScene.h"

D3D11Renderer::CBufferPerScene::CBufferPerScene()
	: worldViewProjection(), ambience()
{
	for (int i{ 0 }; i < 16; i++)
	{
		worldViewProjection[i] = 1.0f;
	}

	for (int i{ 0 }; i < 4; i++)
	{
		ambience[i] = 1.0f;
	}
}
