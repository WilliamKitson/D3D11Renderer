#include "Implimentation.h"

D3D11Renderer::Implimentation::Implimentation()
	: Facade(), device{ nullptr }, context{ nullptr }, swapchain()
{
}

D3D11Renderer::Implimentation::~Implimentation()
{
	cleanup(context);
	cleanup(device);
}

void D3D11Renderer::Implimentation::initialise(HWND input, std::string)
{
	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	D3D11CreateDevice(
		0,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		D3D11_CREATE_DEVICE_DEBUG,
		levels,
		1,
		D3D11_SDK_VERSION,
		&device,
		&supported,
		&context
	);

	swapchain.initialise(
		device, 
		input
	);

	swapchain.bind(context);
}

ID3D11DeviceContext* D3D11Renderer::Implimentation::getContext()
{
	return context;
}

void D3D11Renderer::Implimentation::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}
