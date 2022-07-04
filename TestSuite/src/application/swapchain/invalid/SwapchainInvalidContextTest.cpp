#include "SwapchainInvalidContextTest.h"

SwapchainInvalidContextTest::SwapchainInvalidContextTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain invalid context test" }, window(), device{ nullptr }, context{ nullptr }, result()
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

SwapchainInvalidContextTest::~SwapchainInvalidContextTest()
{
	cleanup(context);
	cleanup(device);
	DestroyWindow(window);
}

std::string SwapchainInvalidContextTest::test()
{
	if (FAILED(result))
	{
		return "swapchain invalid device test failed to initialise\n";
	}

	D3D11Renderer::Swapchain unit;

	unit.initialise(device, window);
	unit.bind(nullptr);

	if (success())
	{
		return std::string();
	}

	return "swapchain invalid device test failed\n";
}

LRESULT CALLBACK SwapchainInvalidContextTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void SwapchainInvalidContextTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void SwapchainInvalidContextTest::initialiseWindowClass()
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

void SwapchainInvalidContextTest::initialiseWindow()
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
}

void SwapchainInvalidContextTest::initialiseD3D11()
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

bool SwapchainInvalidContextTest::success()
{
	ID3D11RenderTargetView* view = nullptr;

	context->OMGetRenderTargets(
		1,
		&view,
		nullptr
	);

	if (!view)
	{
		return true;
	}

	return false;
}
