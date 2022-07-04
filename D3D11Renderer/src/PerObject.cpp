#include "PerObject.h"

D3D11Renderer::PerObject::PerObject()
	: cBuffer{ nullptr }, data()
{
}

D3D11Renderer::PerObject::~PerObject()
{
	cleanup();
}

void D3D11Renderer::PerObject::initialise(ID3D11Device* input)
{
	if (!input)
	{
		return;
	}

	cleanup();

	D3D11_BUFFER_DESC perObjectDescription{
		sizeof(CBufferPerObject),
		D3D11_USAGE_DEFAULT,
		D3D11_BIND_CONSTANT_BUFFER,
		0,
		0,
		0
	};

	D3D11_SUBRESOURCE_DATA subresource{
		&data,
		0,
		0
	};

	HRESULT result = input->CreateBuffer(
		&perObjectDescription,
		&subresource,
		&cBuffer
	);
}

void D3D11Renderer::PerObject::bind(ID3D11DeviceContext* input)
{
	input->VSSetConstantBuffers(
		0,
		1,
		&cBuffer
	);
}

void D3D11Renderer::PerObject::setTransform(float input[16])
{
	for (int i{ 0 }; i < 16; i++)
	{
		data.transform[i] = input[i];
	}
}

void D3D11Renderer::PerObject::setColour(float input[4])
{
	for (int i{ 0 }; i < 4; i++)
	{
		data.colour[i] = input[i];
	}
}

void D3D11Renderer::PerObject::cleanup()
{
	if (cBuffer)
	{
		cBuffer->Release();
		cBuffer = nullptr;
	}
}
