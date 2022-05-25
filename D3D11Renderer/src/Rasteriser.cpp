#include "Rasteriser.h"

D3D11Renderer::Rasteriser::Rasteriser()
	: rasteriser()
{
}

D3D11Renderer::Rasteriser::~Rasteriser()
{
}

void D3D11Renderer::Rasteriser::initialise(ID3D11Device* input)
{
	D3D11_RASTERIZER_DESC description;
	ZeroMemory(&description, sizeof(description));

	description.FrontCounterClockwise = false;
	description.DepthClipEnable = true;
	description.FillMode = D3D11_FILL_SOLID;
	description.CullMode = D3D11_CULL_BACK;

	input->CreateRasterizerState(
		&description,
		&rasteriser
	);
}

void D3D11Renderer::Rasteriser::bind(ID3D11DeviceContext* input)
{
	input->RSSetState(rasteriser);
}
