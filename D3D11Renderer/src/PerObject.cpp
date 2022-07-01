#include "PerObject.h"

D3D11Renderer::PerObject::PerObject()
	: cBuffer{ nullptr }, data()
{
}

D3D11Renderer::PerObject::~PerObject()
{
	if (cBuffer)
	{
		cBuffer->Release();
		cBuffer = nullptr;
	}
}

void D3D11Renderer::PerObject::initialise(ID3D11Device* input)
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

void D3D11Renderer::PerObject::bind(ID3D11DeviceContext* input)
{
	input->VSSetConstantBuffers(
		0,
		1,
		&cBuffer
	);
}
