#include "SwapchainInvalidOverlapTest.h"

SwapchainInvalidOverlapTest::SwapchainInvalidOverlapTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain invalid overlap test" }, window(), device{ nullptr }, context{ nullptr }, result(), depth{ nullptr }
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

SwapchainInvalidOverlapTest::~SwapchainInvalidOverlapTest()
{
	cleanup(depth);
	cleanup(context);
	cleanup(device);
	DestroyWindow(window);
}

std::string SwapchainInvalidOverlapTest::test()
{
	if (FAILED(result))
	{
		return "swapchain invalid overlap test failed to initialise\n";
	}

	D3D11Renderer::Swapchain unit;

	unit.initialise(device, window);
	unit.bind(context);
	unit.overlap(nullptr);

	return std::string();
}

LRESULT CALLBACK SwapchainInvalidOverlapTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void SwapchainInvalidOverlapTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void SwapchainInvalidOverlapTest::initialiseWindowClass()
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

void SwapchainInvalidOverlapTest::initialiseWindow()
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

void SwapchainInvalidOverlapTest::initialiseD3D11()
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
