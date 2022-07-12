#include "Swapchain.h"

D3D11Renderer::Swapchain::Swapchain()
	: resolution(), intervals{ 0 }, state{ nullptr }, view{ nullptr }, depth{ nullptr }
{
}

D3D11Renderer::Swapchain::~Swapchain()
{
	cleanup();
}

void D3D11Renderer::Swapchain::initialise(ID3D11Device* device, HWND window)
{
	try
	{
		validate(device);
		validate(window);
	}
	catch (int)
	{
		return;
	}

	cleanup();
	initialiseState(device,window);
	initialiseView(device);
	initialiseDepth(device);
}

void D3D11Renderer::Swapchain::bind(ID3D11DeviceContext* input)
{
	try
	{
		validate(input);
	}
	catch (int)
	{
		return;
	}

	bindRenderTargets(input);
	bindViewport(input);
}

void D3D11Renderer::Swapchain::update(ID3D11DeviceContext* input)
{
	input->ClearDepthStencilView(
		depth,
		D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL,
		1.0f,
		0
	);

	state->Present(
		intervals,
		0
	);
}

void D3D11Renderer::Swapchain::setResolution(int input[2])
{
	resolution.setResolution(input);
}

void D3D11Renderer::Swapchain::setFull()
{
	intervals = 1;
}

void D3D11Renderer::Swapchain::setHalf()
{
	intervals = 2;
}

void D3D11Renderer::Swapchain::setQuater()
{
	intervals = 4;
}

void D3D11Renderer::Swapchain::setNone()
{
	intervals = 0;
}

void D3D11Renderer::Swapchain::cleanup()
{
	cleanup(depth);
	cleanup(view);
	cleanup(state);
}

void D3D11Renderer::Swapchain::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void D3D11Renderer::Swapchain::validate(IUnknown* input)
{
	if (input)
	{
		return;
	}

	throw int();
}

void D3D11Renderer::Swapchain::validate(HWND input)
{
	if (input)
	{
		return;
	}

	throw int();
}

void D3D11Renderer::Swapchain::initialiseState(ID3D11Device* device, HWND window)
{
	IDXGIFactory* factory = getFactory(device);
	DXGI_SWAP_CHAIN_DESC description = swapchainDescription(window);

	factory->CreateSwapChain(
		device,
		&description,
		&state
	);

	cleanup(factory);
}

IDXGIFactory* D3D11Renderer::Swapchain::getFactory(ID3D11Device* input)
{
	IDXGIAdapter* adapter = getAdapter(input);
	IDXGIFactory* output = nullptr;

	adapter->GetParent(
		__uuidof(IDXGIFactory),
		(void**)&output
	);

	cleanup(adapter);
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

	cleanup(dxgiDevice);
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

DXGI_SWAP_CHAIN_DESC D3D11Renderer::Swapchain::swapchainDescription(HWND input)
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

void D3D11Renderer::Swapchain::initialiseView(ID3D11Device* input)
{
	ID3D11Texture2D* backBuffer = getBackBuffer();

	input->CreateRenderTargetView(
		backBuffer,
		0,
		&view
	);

	cleanup(backBuffer);
}

ID3D11Texture2D* D3D11Renderer::Swapchain::getBackBuffer()
{
	ID3D11Texture2D* output = nullptr;

	state->GetBuffer(
		0,
		__uuidof(ID3D11Texture2D),
		reinterpret_cast<void**>(&output)
	);

	return output;
}

void D3D11Renderer::Swapchain::initialiseDepth(ID3D11Device* input)
{
	ID3D11Texture2D* texture = depthTexture(input);

	input->CreateDepthStencilView(
		texture,
		0,
		&depth
	);

	cleanup(texture);
}

ID3D11Texture2D* D3D11Renderer::Swapchain::depthTexture(ID3D11Device* input)
{
	D3D11_TEXTURE2D_DESC description = depthDescription();
	ID3D11Texture2D* output = nullptr;

	input->CreateTexture2D(
		&description,
		0,
		&output
	);

	return output;
}

D3D11_TEXTURE2D_DESC D3D11Renderer::Swapchain::depthDescription()
{
	D3D11_TEXTURE2D_DESC output = D3D11_TEXTURE2D_DESC();

	output.Width = resolution.getWidth();
	output.Height = resolution.getHeight();
	output.MipLevels = 1;
	output.ArraySize = 1;
	output.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	output.SampleDesc.Count = 1;
	output.SampleDesc.Quality = 0;
	output.Usage = D3D11_USAGE_DEFAULT;
	output.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	output.CPUAccessFlags = 0;
	output.MiscFlags = 0;

	return output;
}

void D3D11Renderer::Swapchain::bindRenderTargets(ID3D11DeviceContext* input)
{
	input->OMSetRenderTargets(
		1,
		&view,
		depth
	);
}

void D3D11Renderer::Swapchain::bindViewport(ID3D11DeviceContext* input)
{
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
