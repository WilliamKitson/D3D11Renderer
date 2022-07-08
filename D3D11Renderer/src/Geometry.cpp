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
	try
	{
		validate(input);
	}
	catch (int)
	{
		return;
	}

	cleanup();

	for (int i{ 0 }; i < 3; i++)
	{
		initialise(i, input);
	}
}

void D3D11Renderer::Geometry::bind(ID3D11DeviceContext* input)
{
	UINT strides[] = {
		sizeof(float) * 3,
		sizeof(float) * 2,
		sizeof(float) * 3
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

void D3D11Renderer::Geometry::pushTexcoord(float input[2])
{
	for (int i{ 0 }; i < 2; i++)
	{
		data[1].push(input[i]);
	}
}

void D3D11Renderer::Geometry::pushNormal(float input[3])
{
	for (int i{ 0 }; i < 3; i++)
	{
		data[2].push(input[i]);
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

void D3D11Renderer::Geometry::validate(IUnknown* input)
{
	if (input)
	{
		return;
	}

	throw int();
}

void D3D11Renderer::Geometry::validate(int input)
{
	if (data[input].getCount())
	{
		return;
	}

	throw int();
}

void D3D11Renderer::Geometry::initialise(int index, ID3D11Device* device)
{
	try
	{
		validate(index);
	}
	catch (int)
	{
		return;
	}

	D3D11_BUFFER_DESC description{
		sizeof(float) * data[index].getCount(),
		D3D11_USAGE_IMMUTABLE,
		D3D11_BIND_VERTEX_BUFFER,
		0,
		0,
		0
	};

	float* raw = rawData(index);

	D3D11_SUBRESOURCE_DATA subresource{
		raw,
		0,
		0
	};

	device->CreateBuffer(
		&description,
		&subresource,
		&vBuffers[index]
	);

	delete[] raw;
}

float* D3D11Renderer::Geometry::rawData(int input)
{
	int size = data[input].getCount();
	float* output = new float[size];

	for (int i{ 0 }; i < size; i++)
	{
		data[input].setIndex(i);
		output[i] = data[input].getCoordinate();
	}

	return output;
}
