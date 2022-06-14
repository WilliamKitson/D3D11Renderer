#include "Swapchain.h"

D3D11Renderer::Swapchain::Swapchain()
	: resolution(), viewport()
{
	viewport = D3D11_VIEWPORT{
		0.0f,
		0.0f,
		960.0f,
		540.0f,
		0.0f,
		1.0f
	};
}

D3D11Renderer::Swapchain::~Swapchain()
{
}

void D3D11Renderer::Swapchain::initialise(ID3D11Device* device, HWND window)
{
}

void D3D11Renderer::Swapchain::bind(ID3D11DeviceContext* input)
{
	input->RSSetViewports(
		1,
		&viewport
	);
}
