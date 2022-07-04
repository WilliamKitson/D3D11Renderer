#include "SwapchainInvalidDeviceTest.h"

SwapchainInvalidDeviceTest::SwapchainInvalidDeviceTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain invalid device test" }, window(), device{ nullptr }, context{ nullptr }, result()
{
}

SwapchainInvalidDeviceTest::~SwapchainInvalidDeviceTest()
{
	cleanup(context);
	cleanup(device);
	DestroyWindow(window);
}

std::string SwapchainInvalidDeviceTest::test()
{
	initialiseWindowClass();

	if (FAILED(result))
	{
		return "swapchain invalid device test failed to initialise window class\n";
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
		return "swapchain invalid device test failed to initialise window\n";
	}

	ShowWindow(
		window,
		nCmdShow
	);

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

	if (FAILED(result))
	{
		return "swapchain invalid device test failed to initialise d3d11\n";
	}

	D3D11Renderer::Swapchain unit;

	unit.initialise(nullptr, window);
	unit.bind(context);

	ID3D11RenderTargetView* view = nullptr;

	context->OMGetRenderTargets(
		1,
		&view,
		nullptr
	);

	if (!view)
	{
		return std::string();
	}

	return "swapchain invalid device test failed\n";
}

LRESULT CALLBACK SwapchainInvalidDeviceTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void SwapchainInvalidDeviceTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void SwapchainInvalidDeviceTest::initialiseWindowClass()
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
