#include "Interleaved.h"

D3D11Renderer::Interleaved::Interleaved()
	: vBuffer{ nullptr }, data()
{
}

D3D11Renderer::Interleaved::~Interleaved()
{
	cleanup();
}

void D3D11Renderer::Interleaved::initialise(ID3D11Device* input)
{
	try
	{
		validate(input);
		validate();
	}
	catch (int)
	{
		return;
	}

	cleanup();
	create(input);
}

void D3D11Renderer::Interleaved::bind(ID3D11DeviceContext* input)
{
	try
	{
		validate(input);
	}
	catch (int)
	{
		return;
	}

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

void D3D11Renderer::Interleaved::push(float input[8])
{
	for (int i{ 0 }; i < 8; i++)
	{
		data.push(input[i]);
	}
}

int D3D11Renderer::Interleaved::getCount()
{
	return data.getCount() / 8;
}

void D3D11Renderer::Interleaved::cleanup()
{
	if (vBuffer)
	{
		vBuffer->Release();
	}
}

void D3D11Renderer::Interleaved::validate(IUnknown* input)
{
	if (input)
	{
		return;
	}

	throw int();
}

void D3D11Renderer::Interleaved::validate()
{
	if (data.getCount())
	{
		return;
	}

	throw int();
}

void D3D11Renderer::Interleaved::create(ID3D11Device* input)
{
	D3D11_BUFFER_DESC description{
		sizeof(float) * data.getCount(),
		D3D11_USAGE_IMMUTABLE,
		D3D11_BIND_VERTEX_BUFFER,
		0,
		0,
		0
	};

	float* rawData = raw();

	D3D11_SUBRESOURCE_DATA subresource{
		rawData,
		0,
		0
	};

	input->CreateBuffer(
		&description,
		&subresource,
		&vBuffer
	);

	delete[] rawData;
}

float* D3D11Renderer::Interleaved::raw()
{
	int size = data.getCount();
	float* output = new float[size];

	for (int i{ 0 }; i < size; i++)
	{
		data.setIndex(i);
		output[i] = data.getCoordinate();
	};

	return output;
}
