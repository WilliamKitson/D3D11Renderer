#include "Rasteriser.h"

D3D11Renderer::Rasteriser::Rasteriser()
	: description(), state{ nullptr }
{
	initialise();
}

D3D11Renderer::Rasteriser::~Rasteriser()
{
	if (state)
	{
		state->Release();
		state = nullptr;
	}
}

void D3D11Renderer::Rasteriser::apply(ID3D11Device* input)
{
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
	ZeroMemory(&description, sizeof(description));
	description.FillMode = D3D11_FILL_SOLID;
	description.CullMode = D3D11_CULL_BACK;
	description.DepthClipEnable = true;
}
