#include "SwapchainResolutionViewportTest.h"

SwapchainResolutionViewportTest::SwapchainResolutionViewportTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain resolution viewport test" }, window(), device{ nullptr }, context{ nullptr }, result()
{
}

SwapchainResolutionViewportTest::~SwapchainResolutionViewportTest()
{
	if (context)
	{
		context->Release();
	}

	if (device)
	{
		device->Release();
	}

	DestroyWindow(window);
}

std::string SwapchainResolutionViewportTest::test()
{
	WNDCLASS windowClass = WNDCLASS();
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = tag.c_str();

	if (!RegisterClass(&windowClass))
	{
		result = E_FAIL;
		return "swapchain resolution viewport test failed to initialise window class\n";
	}

	result = S_OK;

	if (FAILED(result))
	{
		return "swapchain resolution viewport test failed to initialise window class\n";
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
		result = E_FAIL;
		return "swapchain resolution viewport test failed to initialise window\n";
	}

	ShowWindow(
		window,
		nCmdShow
	);

	result = S_OK;

	if (FAILED(result))
	{
		return "swapchain resolution viewport test failed to initialise window\n";
	}

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
		return "swapchain resolution viewport test failed to initialise d3d11\n";
	}

	D3D11Renderer::Swapchain unit;
	unit.initialise(device, window);
	unit.bind(context);

	int resolution[2]{
		2000,
		1000
	};

	unit.setResolution(resolution);
	unit.initialise(device, window);
	unit.bind(context);

	UINT count = 1;
	D3D11_VIEWPORT viewport = D3D11_VIEWPORT();

	context->RSGetViewports(
		&count,
		&viewport
	);

	bool success = true;

	if (viewport.Width != resolution[0])
	{
		success = false;
	}

	if (viewport.Height != resolution[1])
	{
		success = false;
	}

	if (success)
	{
		return std::string();
	}

	return "swapchain resolution viewport test failed\n";
}

LRESULT SwapchainResolutionViewportTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}
