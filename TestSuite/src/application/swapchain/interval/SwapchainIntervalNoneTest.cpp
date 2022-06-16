#include "SwapchainIntervalNoneTest.h"

SwapchainIntervalNoneTest::SwapchainIntervalNoneTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain interval none test" }, window(), device{ nullptr }, context{ nullptr }, result(), unit()
{
}

SwapchainIntervalNoneTest::~SwapchainIntervalNoneTest()
{
	cleanup(context);
	cleanup(device);
	DestroyWindow(window);
}

std::string SwapchainIntervalNoneTest::test()
{
	initialiseWindowClass();

	if (FAILED(result))
	{
		return "swapchain interval full test failed to initialise window class\n";
	}

	initialiseWindow();

	if (FAILED(result))
	{
		return "swapchain interval full test failed to initialise window\n";
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
		return "swapchain interval full test failed to initialise d3d11\n";
	}

	unit.initialise(device, window);
	unit.bind(context);
	unit.setFull();
	unit.setNone();

	int framerate = 0;
	double elapced = 0.0f;
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	while (elapced < 1.0f)
	{
		unit.update();
		elapced += (float)std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		framerate++;
	}

	framerate--;

	if (framerate > 144)
	{
		return std::string();
	}

	return "swapchain interval none test failed\n";
}

LRESULT CALLBACK SwapchainIntervalNoneTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void SwapchainIntervalNoneTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void SwapchainIntervalNoneTest::initialiseWindowClass()
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

void SwapchainIntervalNoneTest::initialiseWindow()
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
