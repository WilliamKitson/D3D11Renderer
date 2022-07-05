#include "CBufferPerScene.h"

D3D11Renderer::CBufferPerScene::CBufferPerScene()
	: worldViewProjection()
{
	for (int i{ 0 }; i < 16; i++)
	{
		worldViewProjection[i] = 1.0f;
	}
}
