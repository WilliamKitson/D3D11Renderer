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

	try
	{
		validate(1);
	}
	catch (int)
	{
		return;
	}

	D3D11_BUFFER_DESC description{
		sizeof(float) * data[1].getCount(),
		D3D11_USAGE_IMMUTABLE,
		D3D11_BIND_VERTEX_BUFFER,
		0,
		0,
		0
	};

	int size = data[1].getCount();
	float* output = new float[size];

	for (int i{ 0 }; i < size; i++)
	{
		data[1].setIndex(i);
		output[i] = data[1].getCoordinate();
	}

	D3D11_SUBRESOURCE_DATA subresource{
		output,
		0,
		0
	};

	input->CreateBuffer(
		&description,
		&subresource,
		&vBuffers[1]
	);

	delete[] output;
}

void D3D11Renderer::Geometry::bind(ID3D11DeviceContext* input)
{
	UINT strides[] = {
		sizeof(float) * 3,
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

void D3D11Renderer::Geometry::pushTexcoord(float input[2])
{
	for (int i{ 0 }; i < 2; i++)
	{
		data[1].push(input[i]);
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

void D3D11Renderer::Geometry::validate(int input)
{
	if (data[input].getCount())
	{
		return;
	}

	throw int();
}

void D3D11Renderer::Geometry::positions(ID3D11Device* input)
{
	try
	{
		validate(0);
	}
	catch (int)
	{
		return;
	}

	D3D11_BUFFER_DESC description{
		sizeof(float) * data[0].getCount(),
		D3D11_USAGE_IMMUTABLE,
		D3D11_BIND_VERTEX_BUFFER,
		0,
		0,
		0
	};

	float* rawData = rawPositions();

	D3D11_SUBRESOURCE_DATA subresource{
		rawData,
		0,
		0
	};

	input->CreateBuffer(
		&description,
		&subresource,
		&vBuffers[0]
	);

	delete[] rawData;
}

float* D3D11Renderer::Geometry::rawPositions()
{
	int size = data[0].getCount();
	float* output = new float[size];

	for (int i{ 0 }; i < size; i++)
	{
		data[0].setIndex(i);
		output[i] = data[0].getCoordinate();
	}

	return output;
}
