#include "SwapchainDefaultViewTest.h"

SwapchainDefaultViewTest::SwapchainDefaultViewTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain default view test" }, window(), device{ nullptr }, context{ nullptr }
{
}

SwapchainDefaultViewTest::~SwapchainDefaultViewTest()
{
	if (context)
	{
		context->Release();
		context = nullptr;
	}

	if (device)
	{
		device->Release();
		device = nullptr;
	}

	DestroyWindow(window);
}

std::string SwapchainDefaultViewTest::test()
{
	WNDCLASS windowClass = WNDCLASS();
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = tag.c_str();

	if (!RegisterClass(&windowClass))
	{
		return "swapchain default view test failed to initialise window class\n";
	}

	window = CreateWindow(
		tag.c_str(),
		tag.c_str(),
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		960,
		540,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!window)
	{
		return "swapchain default view test failed to initialise window\n";
	}

	ShowWindow(
		window,
		nCmdShow
	);

	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	HRESULT output = D3D11CreateDevice(
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

	if (FAILED(output))
	{
		return "swapchain default view test failed to initialise d3d11\n";
	}

	D3D11Renderer::Swapchain unit;

	unit.initialise(device, window);
	unit.bind(context);

	ID3D11RenderTargetView* view = nullptr;
	ID3D11DepthStencilView* depth = nullptr;

	context->OMGetRenderTargets(
		1,
		&view,
		&depth
	);

	if (!view)
	{
		return "swapchain default view test failed to initialise view\n";
	}

	ID3D11Texture2D* backBuffer = nullptr;
	view->GetResource(reinterpret_cast<ID3D11Resource**>(&backBuffer));
	view->Release();
	view = nullptr;

	D3D11_TEXTURE2D_DESC texture;
	backBuffer->GetDesc(&texture);

	if (backBuffer)
	{
		backBuffer->Release();
		backBuffer = nullptr;
	}

	D3D11_TEXTURE2D_DESC successful = D3D11_TEXTURE2D_DESC();
	successful.Width = 960;
	successful.Height = 540;
	successful.MipLevels = 1;
	successful.ArraySize = 1;
	successful.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	successful.SampleDesc.Count = 1;
	successful.SampleDesc.Quality = 0;
	successful.Usage = D3D11_USAGE_DEFAULT;
	successful.BindFlags = 32;
	successful.CPUAccessFlags = 0;
	successful.MiscFlags = 0;

	bool equal = true;

	if (texture.Width != successful.Width)
	{
		equal = false;
	}

	if (texture.Height != successful.Height)
	{
		equal = false;
	}

	if (texture.MipLevels != successful.MipLevels)
	{
		equal = false;
	}

	if (texture.ArraySize != successful.ArraySize)
	{
		equal = false;
	}

	if (texture.Format != successful.Format)
	{
		equal = false;
	}

	if (texture.SampleDesc.Count != successful.SampleDesc.Count)
	{
		equal = false;
	}

	if (texture.SampleDesc.Quality != successful.SampleDesc.Quality)
	{
		equal = false;
	}

	if (texture.Usage != successful.Usage)
	{
		equal = false;
	}

	if (texture.BindFlags != successful.BindFlags)
	{
		equal = false;
	}

	if (texture.CPUAccessFlags != successful.CPUAccessFlags)
	{
		equal = false;
	}

	if (texture.MiscFlags != successful.MiscFlags)
	{
		equal = false;
	}

	if (equal)
	{
		return std::string();
	}

	return "swapchain default view test failed\n";
}

LRESULT SwapchainDefaultViewTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}
