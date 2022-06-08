#include "Rasteriser.h"

D3D11Renderer::Rasteriser::Rasteriser()
	: description(), rasteriser{ nullptr }
{
	ZeroMemory(&description, sizeof(description));
	description.FrontCounterClockwise = false;
	description.DepthClipEnable = true;
	description.FillMode = D3D11_FILL_SOLID;
	description.CullMode = D3D11_CULL_BACK;
}

D3D11Renderer::Rasteriser::~Rasteriser()
{
}

void D3D11Renderer::Rasteriser::apply(ID3D11Device* input)
{
	input->CreateRasterizerState(
		&description,
		&rasteriser
	);
}

void D3D11Renderer::Rasteriser::bind(ID3D11DeviceContext* input)
{
	input->RSSetState(rasteriser);
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
