#include "Directional.h"

D3D11Renderer::Directional::Directional()
	: cBuffer{ nullptr }, data()
{
	for (int i{ 0 }; i < 4; i++)
	{
		data[i] = 0.0f;
	}

	for (int i{ 4 }; i < 8; i++)
	{
		data[i] = 1.0f;
	}
}

D3D11Renderer::Directional::~Directional()
{
	if (cBuffer)
	{
		cBuffer->Release();
	}
}

void D3D11Renderer::Directional::initialise(ID3D11Device* input)
{
	if (cBuffer)
	{
		cBuffer->Release();
	}

	D3D11_BUFFER_DESC description{
		sizeof(data),
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

	input->CreateBuffer(
		&description,
		&subresource,
		&cBuffer
	);
}

void D3D11Renderer::Directional::apply(ID3D11DeviceContext* input)
{
	input->UpdateSubresource(
		cBuffer,
		0,
		0,
		&data,
		0,
		0
	);
}

void D3D11Renderer::Directional::bind(ID3D11DeviceContext* input)
{
	input->VSSetConstantBuffers(
		2,
		1,
		&cBuffer
	);
}

void D3D11Renderer::Directional::setDirection(float input[4])
{
	for (int i{ 0 }; i < 4; i++)
	{
		data[i] = input[i];
	}
}

void D3D11Renderer::Directional::setColour(float input[4])
{
	for (int i{ 0 }; i < 4; i++)
	{
		data[4 + i] = input[i];
	}
}
