#include "Swapchain.h"

D3D11Renderer::Swapchain::Swapchain()
	: resolution(), state{ nullptr }, view{ nullptr }
{
}

D3D11Renderer::Swapchain::~Swapchain()
{
	if (view)
	{
		view->Release();
		view = nullptr;
	}

	if (state)
	{
		state->Release();
		state = nullptr;
	}
}

void D3D11Renderer::Swapchain::initialise(ID3D11Device* device, HWND window)
{
	IDXGIFactory* factory = getFactory(device);

	DXGI_SWAP_CHAIN_DESC description = DXGI_SWAP_CHAIN_DESC();

	description.BufferDesc.Width = resolution.getWidth();
	description.BufferDesc.Height = resolution.getHeight();
	description.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	description.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	description.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	description.SampleDesc.Count = 1;
	description.SampleDesc.Quality = 0;
	description.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	description.BufferCount = 1;
	description.OutputWindow = window;
	description.Windowed = true;
	description.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	description.Flags = 0;

	HRESULT result = factory->CreateSwapChain(
		device,
		&description,
		&state
	);

	factory->Release();
	factory = nullptr;

	if (FAILED(result))
	{
		return;
	}

	ID3D11Texture2D* backBuffer = nullptr;

	result = state->GetBuffer(
		0,
		__uuidof(ID3D11Texture2D),
		reinterpret_cast<void**>(&backBuffer)
	);

	if (FAILED(result))
	{
		return;
	}

	device->CreateRenderTargetView(
		backBuffer,
		0,
		&view
	);

	if (backBuffer)
	{
		backBuffer->Release();
		backBuffer = nullptr;
	}
}

void D3D11Renderer::Swapchain::bind(ID3D11DeviceContext* input)
{
	input->OMSetRenderTargets(
		1,
		&view,
		nullptr
	);

	D3D11_VIEWPORT viewport{
		0.0f,
		0.0f,
		(float)resolution.getWidth(),
		(float)resolution.getHeight(),
		0.0f,
		1.0f
	};

	input->RSSetViewports(
		1,
		&viewport
	);
}

IDXGIFactory* D3D11Renderer::Swapchain::getFactory(ID3D11Device* device)
{
	IDXGIDevice* dxgiDevice = nullptr;

	device->QueryInterface(__uuidof(IDXGIDevice), (void**)&dxgiDevice);

	if (!dxgiDevice)
	{
		return nullptr;
	}

	IDXGIAdapter* adapter = nullptr;

	dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&adapter);
	dxgiDevice->Release();
	dxgiDevice = nullptr;

	IDXGIFactory* factory = nullptr;

	adapter->GetParent(__uuidof(IDXGIFactory), (void**)&factory);
	adapter->Release();
	adapter = nullptr;

	return factory;
}
