#include "SwapchainResolutionViewportTest.h"

SwapchainResolutionViewportTest::SwapchainResolutionViewportTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain resolution viewport test" }, window(), device{ nullptr }, context{ nullptr }, result()
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

SwapchainResolutionViewportTest::~SwapchainResolutionViewportTest()
{
	cleanup(context);
	cleanup(device);
	DestroyWindow(window);
}

std::string SwapchainResolutionViewportTest::test()
{
	if (FAILED(result))
	{
		return "swapchain resolution viewport test failed to initialise\n";
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

	if (successful(viewport(), resolution))
	{
		return std::string();
	}

	return "swapchain resolution viewport test failed\n";
}

LRESULT SwapchainResolutionViewportTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void SwapchainResolutionViewportTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void SwapchainResolutionViewportTest::initialiseWindowClass()
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

void SwapchainResolutionViewportTest::initialiseWindow()
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

void SwapchainResolutionViewportTest::initialiseD3D11()
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

D3D11_VIEWPORT SwapchainResolutionViewportTest::viewport()
{
	UINT count = 1;
	D3D11_VIEWPORT output = D3D11_VIEWPORT();

	context->RSGetViewports(
		&count,
		&output
	);

	return output;
}

bool SwapchainResolutionViewportTest::successful(D3D11_VIEWPORT view, int resolution[2])
{
	if (view.Width != resolution[0])
	{
		return false;
	}

	if (view.Height != resolution[1])
	{
		return false;
	}

	return true;
}
