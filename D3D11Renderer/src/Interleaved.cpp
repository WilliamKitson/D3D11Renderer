#include "Interleaved.h"

D3D11Renderer::Interleaved::Interleaved()
	: vBuffer{ nullptr }, data()
{
}

D3D11Renderer::Interleaved::~Interleaved()
{
	if (vBuffer)
	{
		vBuffer->Release();
	}
}

void D3D11Renderer::Interleaved::initialise(ID3D11Device* input)
{
	if (vBuffer)
	{
		vBuffer->Release();
	}

	if (!data.getCount())
	{
		return;
	}

	D3D11_BUFFER_DESC description{
		sizeof(float) * data.getCount(),
		D3D11_USAGE_IMMUTABLE,
		D3D11_BIND_VERTEX_BUFFER,
		0,
		0,
		0
	};

	int size = data.getCount();
	float* raw = new float[size];

	for (int i{ 0 }; i < size; i++)
	{
		data.setIndex(i);
		raw[i] = data.getCoordinate();
	};

	D3D11_SUBRESOURCE_DATA subresource{
		raw,
		0,
		0
	};

	input->CreateBuffer(
		&description,
		&subresource,
		&vBuffer
	);

	delete[] raw;
}

void D3D11Renderer::Interleaved::bind(ID3D11DeviceContext* input)
{
	UINT strides[] = {
		sizeof(float) * 8
	};

	UINT offsets[] = {
		0
	};

	input->IASetVertexBuffers(
		0,
		1,
		&vBuffer,
		strides,
		offsets
	);
}

void D3D11Renderer::Interleaved::pushVertex(float input[8])
{
	for (int i{ 0 }; i < 8; i++)
	{
		data.push(input[i]);
	}
}
