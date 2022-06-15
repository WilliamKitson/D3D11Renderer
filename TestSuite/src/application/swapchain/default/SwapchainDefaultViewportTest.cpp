#include "SwapchainDefaultViewportTest.h"

SwapchainDefaultViewportTest::SwapchainDefaultViewportTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain default viewport D3D11" }, window(), device{ nullptr }, context{ nullptr }
{
}

SwapchainDefaultViewportTest::~SwapchainDefaultViewportTest()
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

std::string SwapchainDefaultViewportTest::test()
{
	if (FAILED(initialiseWindow()))
	{
		return "swapchain default viewport test window failed to initialise\n";
	}

	if (FAILED(initialiseD3D11()))
	{
		return "swapchain default viewport test D3D11 failed to initialise\n";
	}

	D3D11Renderer::Swapchain unit;

	unit.initialise(device, window);
	unit.bind(context);

	if (successful(viewport()))
	{
		return std::string();
	}

	return "swapchain default viewport test failed\n";
}

LRESULT CALLBACK SwapchainDefaultViewportTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

HRESULT SwapchainDefaultViewportTest::initialiseWindow()
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

HRESULT SwapchainDefaultViewportTest::initialiseWindowClass()
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

HRESULT SwapchainDefaultViewportTest::initialiseD3D11()
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

D3D11_VIEWPORT SwapchainDefaultViewportTest::viewport()
{
	UINT count = 1;
	D3D11_VIEWPORT output = D3D11_VIEWPORT();

	context->RSGetViewports(
		&count,
		&output
	);

	return output;
}

bool SwapchainDefaultViewportTest::successful(D3D11_VIEWPORT input)
{
	if (input.TopLeftX != 0.0f)
	{
		return false;
	}

	if (input.TopLeftY != 0.0f)
	{
		return false;
	}

	if (input.Width != 960.0f)
	{
		return false;
	}

	if (input.Height != 540.0f)
	{
		return false;
	}

	if (input.MinDepth != 0.0f)
	{
		return false;
	}

	if (input.MaxDepth != 1.0f)
	{
		return false;
	}

	return true;
}
