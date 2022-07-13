#include "Sampler.h"

D3D11Renderer::Sampler::Sampler()
	: state{ nullptr }, description{ D3D11_SAMPLER_DESC() }
{
	description.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	description.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	description.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	description.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	description.MaxLOD = D3D11_FLOAT32_MAX;
}

D3D11Renderer::Sampler::~Sampler()
{
	if (state)
	{
		state->Release();
	}
}

void D3D11Renderer::Sampler::initialise(ID3D11Device* input)
{
	input->CreateSamplerState(
		&description,
		&state
	);
}

void D3D11Renderer::Sampler::bind(ID3D11DeviceContext* input)
{
	input->PSSetSamplers(
		0,
		1,
		&state
	);
}
