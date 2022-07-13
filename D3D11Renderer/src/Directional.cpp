#include "Directional.h"

D3D11Renderer::Directional::Directional()
	: cBuffer{ nullptr }, data()
{
	for (int i{ 0 }; i < 4; i++)
	{
		data[i] = 0.0f;
	}

	colour();
}

D3D11Renderer::Directional::~Directional()
{
	cleanup();
}

void D3D11Renderer::Directional::initialise(ID3D11Device* input)
{
	try
	{
		validate(input);
	}
	catch (int)
	{
		return;
	}

	cleanup();
	create(input);
}

void D3D11Renderer::Directional::apply(ID3D11DeviceContext* input)
{
	try
	{
		validate(input);
	}
	catch (int)
	{
		return;
	}

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
	try
	{
		validate(input);
	}
	catch (int)
	{
		return;
	}

	input->VSSetConstantBuffers(
		2,
		1,
		&cBuffer
	);
}

void D3D11Renderer::Directional::setDirection(float input[3])
{
	for (int i{ 0 }; i < 3; i++)
	{
		data[i] = input[i];
	}
}

void D3D11Renderer::Directional::setColour(float input[3])
{
	for (int i{ 0 }; i < 3; i++)
	{
		data[4 + i] = input[i];
	}
}

void D3D11Renderer::Directional::colour()
{
	for (int i{ 4 }; i < 8; i++)
	{
		data[i] = 1.0f;
	}
}

void D3D11Renderer::Directional::cleanup()
{
	if (cBuffer)
	{
		cBuffer->Release();
	}
}

void D3D11Renderer::Directional::validate(IUnknown* input)
{
	if (input)
	{
		return;
	}

	throw int();
}

void D3D11Renderer::Directional::create(ID3D11Device* input)
{
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
