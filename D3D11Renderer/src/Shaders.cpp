#include "Shaders.h"

D3D11Renderer::Shaders::Shaders()
	: vShader{ nullptr }, pShader{ nullptr }
{
}

D3D11Renderer::Shaders::~Shaders()
{
	if (pShader)
	{
		pShader->Release();
	}

	if (vShader)
	{
		vShader->Release();
	}
}

void D3D11Renderer::Shaders::initialise(ID3D11Device* input)
{
	vLoad(input);

	ID3DBlob* blob = nullptr;

	D3DCompileFromFile(
		L"assets/shaders/shaders.hlsl",
		0,
		0,
		"PShader",
		"ps_4_0",
		0,
		0,
		&blob,
		nullptr
	);

	input->CreatePixelShader(
		blob->GetBufferPointer(),
		blob->GetBufferSize(),
		NULL,
		&pShader
	);
}

void D3D11Renderer::Shaders::bind(ID3D11DeviceContext* input)
{
	input->VSSetShader(
		vShader,
		0,
		0
	);

	input->PSSetShader(
		pShader,
		0,
		0
	);
}

void D3D11Renderer::Shaders::vLoad(ID3D11Device* input)
{
	ID3DBlob* blob = nullptr;

	D3DCompileFromFile(
		L"assets/shaders/shaders.hlsl",
		0,
		0,
		"VShader",
		"vs_4_0",
		0,
		0,
		&blob,
		nullptr
	);

	input->CreateVertexShader(
		blob->GetBufferPointer(),
		blob->GetBufferSize(),
		NULL,
		&vShader
	);
}
