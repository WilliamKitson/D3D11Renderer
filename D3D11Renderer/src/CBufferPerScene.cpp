#include "CBufferPerScene.h"

D3D11Renderer::CBufferPerScene::CBufferPerScene()
	: worldViewProjection(), ambience()
{
	initWorldViewProjection();

	for (int i{ 0 }; i < 4; i++)
	{
		ambience[i] = 1.0f;
	}
}

void D3D11Renderer::CBufferPerScene::initWorldViewProjection()
{
	for (int i{ 0 }; i < 16; i++)
	{
		worldViewProjection[i] = 1.0f;
	}
}
