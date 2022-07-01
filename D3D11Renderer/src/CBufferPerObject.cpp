#include "CBufferPerObject.h"

D3D11Renderer::CBufferPerObject::CBufferPerObject()
	: transform()
{
	for (int i{ 0 }; i < 16; i++)
	{
		transform[i] = 1.0f;
	}
}
