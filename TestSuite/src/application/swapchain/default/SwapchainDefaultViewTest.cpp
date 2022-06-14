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
	if (FAILED(initialiseWindow()))
	{
		return "swapchain default view test window failed to initialise\n";
	}

	if (FAILED(initialiseD3D11()))
	{
		return "swapchain default view test d3d11 failed to initialise\n";
	}

	D3D11Renderer::Swapchain unit;

	unit.initialise(device, window);
	unit.bind(context);

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

	D3D11_TEXTURE2D_DESC comparison = texture();

	bool equal = true;

	if (comparison.Width != successful.Width)
	{
		equal = false;
	}

	if (comparison.Height != successful.Height)
	{
		equal = false;
	}

	if (comparison.MipLevels != successful.MipLevels)
	{
		equal = false;
	}

	if (comparison.ArraySize != successful.ArraySize)
	{
		equal = false;
	}

	if (comparison.Format != successful.Format)
	{
		equal = false;
	}

	if (comparison.SampleDesc.Count != successful.SampleDesc.Count)
	{
		equal = false;
	}

	if (comparison.SampleDesc.Quality != successful.SampleDesc.Quality)
	{
		equal = false;
	}

	if (comparison.Usage != successful.Usage)
	{
		equal = false;
	}

	if (comparison.BindFlags != successful.BindFlags)
	{
		equal = false;
	}

	if (comparison.CPUAccessFlags != successful.CPUAccessFlags)
	{
		equal = false;
	}

	if (comparison.MiscFlags != successful.MiscFlags)
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

HRESULT SwapchainDefaultViewTest::initialiseWindow()
{
	if (FAILED(initialiseWindowClass()))
	{
		return E_FAIL;
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
		return E_FAIL;
	}

	ShowWindow(
		window,
		nCmdShow
	);

	return S_OK;
}

HRESULT SwapchainDefaultViewTest::initialiseWindowClass()
{
	WNDCLASS windowClass = WNDCLASS();
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = tag.c_str();

	if (!RegisterClass(&windowClass))
	{
		return E_FAIL;
	}

	return S_OK;
}

HRESULT SwapchainDefaultViewTest::initialiseD3D11()
{
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

	return output;
}

D3D11_TEXTURE2D_DESC SwapchainDefaultViewTest::texture()
{
	ID3D11RenderTargetView* view = nullptr;

	context->OMGetRenderTargets(
		1,
		&view,
		nullptr
	);

	if (!view)
	{
		return D3D11_TEXTURE2D_DESC();
	}

	ID3D11Texture2D* backBuffer = nullptr;
	view->GetResource(reinterpret_cast<ID3D11Resource**>(&backBuffer));
	view->Release();
	view = nullptr;

	D3D11_TEXTURE2D_DESC output;
	backBuffer->GetDesc(&output);
	backBuffer->Release();
	backBuffer = nullptr;

	return output;
}
