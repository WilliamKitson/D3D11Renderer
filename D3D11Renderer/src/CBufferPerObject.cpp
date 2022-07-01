#include "CBufferPerObject.h"

D3D11Renderer::CBufferPerObject::CBufferPerObject()
	: transform(), colour()
{
	for (int i{ 0 }; i < 16; i++)
	{
		transform[i] = 1.0f;
	}

	for (int i{ 0 }; i < 4; i++)
	{
		colour[i] = 1.0f;
	}
}
