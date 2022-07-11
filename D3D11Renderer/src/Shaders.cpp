#include "Shaders.h"

D3D11Renderer::Shaders::Shaders()
	: vShader{ nullptr }, pShader{ nullptr }
{
}

D3D11Renderer::Shaders::~Shaders()
{
	cleanup(pShader);
	cleanup(vShader);
}

void D3D11Renderer::Shaders::initialise(ID3D11Device* input)
{
	vLoad(input);
	pLoad(input);
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

void D3D11Renderer::Shaders::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
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

void D3D11Renderer::Shaders::pLoad(ID3D11Device* input)
{
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
