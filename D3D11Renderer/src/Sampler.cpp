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
	cleanup();
}

void D3D11Renderer::Sampler::initialise(ID3D11Device* input)
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

	input->CreateSamplerState(
		&description,
		&state
	);
}

void D3D11Renderer::Sampler::bind(ID3D11DeviceContext* input)
{
	try
	{
		validate(input);
	}
	catch (int)
	{
		return;
	}

	input->PSSetSamplers(
		0,
		1,
		&state
	);
}

void D3D11Renderer::Sampler::cleanup()
{
	if (state)
	{
		state->Release();
	}
}

void D3D11Renderer::Sampler::validate(IUnknown* input)
{
	if (input)
	{
		return;
	}

	throw int();
}
