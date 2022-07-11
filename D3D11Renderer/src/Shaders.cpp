#include "Shaders.h"

D3D11Renderer::Shaders::Shaders()
	: vShader{ nullptr }
{
}

D3D11Renderer::Shaders::~Shaders()
{
	if (vShader)
	{
		vShader->Release();
	}
}

void D3D11Renderer::Shaders::initialise(ID3D11Device* input)
{
	vLoad(input);
}

void D3D11Renderer::Shaders::bind(ID3D11DeviceContext* input)
{
	input->VSSetShader(
		vShader,
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
