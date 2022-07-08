#include "Geometry.h"

D3D11Renderer::Geometry::Geometry()
	: vBuffers(), data()
{
}

D3D11Renderer::Geometry::~Geometry()
{
	cleanup();
}

void D3D11Renderer::Geometry::initialise(ID3D11Device* input)
{
	cleanup();
	positions(input);
}

void D3D11Renderer::Geometry::bind(ID3D11DeviceContext* input)
{
	UINT strides[] = {
		sizeof(float),
		sizeof(float),
		0
	};

	UINT offsets[] = {
		0,
		0,
		0
	};

	input->IASetVertexBuffers(
		0,
		3,
		vBuffers,
		strides,
		offsets
	);
}

void D3D11Renderer::Geometry::pushPosition(float input[3])
{
	for (int i{ 0 }; i < 3; i++)
	{
		data[0].push(input[i]);
	}
}

void D3D11Renderer::Geometry::cleanup()
{
	for (int i{ 0 }; i < 3; i++)
	{
		cleanup(vBuffers[i]);
	}
}

void D3D11Renderer::Geometry::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void D3D11Renderer::Geometry::positions(ID3D11Device* input)
{
	if (!data[0].getCount())
	{
		return;
	}

	int size = data[0].getCount();

	D3D11_BUFFER_DESC description{
		sizeof(float) * size,
		D3D11_USAGE_IMMUTABLE,
		D3D11_BIND_VERTEX_BUFFER,
		0,
		0,
		0
	};

	float* positions = new float[size];

	for (int i{ 0 }; i < size; i++)
	{
		data[0].setIndex(i);
		positions[i] = data[0].getCoordinate();
	}

	D3D11_SUBRESOURCE_DATA subresource{
		positions,
		0,
		0
	};

	input->CreateBuffer(
		&description,
		&subresource,
		&vBuffers[0]
	);

	delete[] positions;
}
