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

void D3D11Renderer::PerObject::apply(ID3D11DeviceContext* input)
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

void D3D11Renderer::PerObject::bind(ID3D11DeviceContext* input)
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
		0,
		1,
		&cBuffer
	);
}

void D3D11Renderer::PerObject::setTransform(float input[16])
{
	DirectX::XMMATRIX transform = calculate(input);

	data.transform[0] = transform._11;
	data.transform[1] = transform._12;
	data.transform[2] = transform._13;
	data.transform[3] = transform._14;
	data.transform[4] = transform._21;
	data.transform[5] = transform._22;
	data.transform[6] = transform._23;
	data.transform[7] = transform._24;
	data.transform[8] = transform._31;
	data.transform[9] = transform._32;
	data.transform[10] = transform._33;
	data.transform[11] = transform._34;
	data.transform[12] = transform._41;
	data.transform[13] = transform._42;
	data.transform[14] = transform._43;
	data.transform[15] = transform._44;
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

void D3D11Renderer::PerObject::validate(IUnknown* input)
{
	if (input)
	{
		return;
	}

	throw int();
}

void D3D11Renderer::PerObject::create(ID3D11Device* input)
{
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

DirectX::XMMATRIX D3D11Renderer::PerObject::calculate(float input[16])
{
	DirectX::XMMATRIX position = DirectX::XMMatrixTranslation(
		input[0],
		input[1],
		input[2]
	);

	DirectX::XMMATRIX rotation = DirectX::XMMatrixRotationRollPitchYaw(
		input[4],
		input[5],
		input[6]
	);

	DirectX::XMMATRIX scale = DirectX::XMMatrixScaling(
		input[8],
		input[9],
		input[10]
	);

	return position * rotation * scale;
}
