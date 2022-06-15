#include "SwapchainDefaultViewportTest.h"

SwapchainDefaultViewportTest::SwapchainDefaultViewportTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain default viewport test" }, window(), device{ nullptr }, context{ nullptr }, result()
{
	initialiseWindowClass();

	if (FAILED(result))
	{
		return;
	}

	initialiseWindow();

	if (FAILED(result))
	{
		return;
	}

	initialiseD3D11();
}

SwapchainDefaultViewportTest::~SwapchainDefaultViewportTest()
{
	cleanup(context);
	cleanup(device);
	DestroyWindow(window);
}

std::string SwapchainDefaultViewportTest::test()
{
	if (FAILED(result))
	{
		return "swapchain default viewport test failed to initialise\n";
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

void SwapchainDefaultViewportTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
		input = nullptr;
	}
}

void SwapchainDefaultViewportTest::initialiseWindowClass()
{
	WNDCLASS windowClass = WNDCLASS();
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = tag.c_str();

	if (!RegisterClass(&windowClass))
	{
		result = E_FAIL;
		return;
	}

	result = S_OK;
}

void SwapchainDefaultViewportTest::initialiseWindow()
{
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
		result = E_FAIL;
		return;
	}

	ShowWindow(
		window,
		nCmdShow
	);

	result = S_OK;
}

void SwapchainDefaultViewportTest::initialiseD3D11()
{
	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	result = D3D11CreateDevice(
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
