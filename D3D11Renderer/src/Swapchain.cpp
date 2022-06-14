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
	initialiseState(
		device,
		window
	);

	if (!state)
	{
		return;
	}

	ID3D11Texture2D* backBuffer = nullptr;

	state->GetBuffer(
		0,
		__uuidof(ID3D11Texture2D),
		reinterpret_cast<void**>(&backBuffer)
	);

	if (!backBuffer)
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

void D3D11Renderer::Swapchain::initialiseState(ID3D11Device* device, HWND window)
{
	IDXGIFactory* factory = getFactory(device);
	DXGI_SWAP_CHAIN_DESC description = getDescription(window);

	HRESULT result = factory->CreateSwapChain(
		device,
		&description,
		&state
	);

	factory->Release();
	factory = nullptr;
}

IDXGIFactory* D3D11Renderer::Swapchain::getFactory(ID3D11Device* input)
{
	IDXGIAdapter* adapter = getAdapter(input);
	IDXGIFactory* output = nullptr;

	adapter->GetParent(
		__uuidof(IDXGIFactory),
		(void**)&output
	);

	adapter->Release();
	adapter = nullptr;

	return output;
}

IDXGIAdapter* D3D11Renderer::Swapchain::getAdapter(ID3D11Device* input)
{
	IDXGIDevice* dxgiDevice = getDevice(input);
	IDXGIAdapter* output = nullptr;

	dxgiDevice->GetParent(
		__uuidof(IDXGIAdapter),
		(void**)&output
	);

	dxgiDevice->Release();
	dxgiDevice = nullptr;

	return output;
}

IDXGIDevice* D3D11Renderer::Swapchain::getDevice(ID3D11Device* input)
{
	IDXGIDevice* output = nullptr;

	input->QueryInterface(
		__uuidof(IDXGIDevice),
		(void**)&output
	);

	return output;
}

DXGI_SWAP_CHAIN_DESC D3D11Renderer::Swapchain::getDescription(HWND input)
{
	DXGI_SWAP_CHAIN_DESC output = DXGI_SWAP_CHAIN_DESC();

	output.BufferDesc.Width = resolution.getWidth();
	output.BufferDesc.Height = resolution.getHeight();
	output.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	output.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	output.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	output.SampleDesc.Count = 1;
	output.SampleDesc.Quality = 0;
	output.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	output.BufferCount = 1;
	output.OutputWindow = input;
	output.Windowed = true;
	output.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	output.Flags = 0;

	return output;
}
