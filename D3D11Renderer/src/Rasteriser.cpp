#include "Rasteriser.h"

D3D11Renderer::Rasteriser::Rasteriser()
	: description(), state{ nullptr }
{
	initialise();
}

D3D11Renderer::Rasteriser::~Rasteriser()
{
	cleanup();
}

void D3D11Renderer::Rasteriser::apply(ID3D11Device* input)
{
	cleanup();

	input->CreateRasterizerState(
		&description,
		&state
	);
}

void D3D11Renderer::Rasteriser::bind(ID3D11DeviceContext* input)
{
	input->RSSetState(state);
}

void D3D11Renderer::Rasteriser::setWireframe()
{
	description.FillMode = D3D11_FILL_WIREFRAME;
}

void D3D11Renderer::Rasteriser::setSolid()
{
	description.FillMode = D3D11_FILL_SOLID;
}

void D3D11Renderer::Rasteriser::setNone()
{
	description.CullMode = D3D11_CULL_NONE;
}

void D3D11Renderer::Rasteriser::setFront()
{
	description.CullMode = D3D11_CULL_FRONT;
}

void D3D11Renderer::Rasteriser::setBack()
{
	description.CullMode = D3D11_CULL_BACK;
}

void D3D11Renderer::Rasteriser::initialise()
{
	description = {
		D3D11_FILL_SOLID,
		D3D11_CULL_BACK,
		false,
		0,
		0.0f,
		0.0f,
		true,
		false,
		false,
		false
	};
}

void D3D11Renderer::Rasteriser::cleanup()
{
	if (state)
	{
		state->Release();
	}
}
