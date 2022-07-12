#include "SwapchainIntervalQuaterTest.h"

SwapchainIntervalQuaterTest::SwapchainIntervalQuaterTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, tag{ L"swapchain interval quater test" }, window(), device{ nullptr }, context{ nullptr }, result(), unit()
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

SwapchainIntervalQuaterTest::~SwapchainIntervalQuaterTest()
{
	cleanup(context);
	cleanup(device);
	DestroyWindow(window);
}

std::string SwapchainIntervalQuaterTest::test()
{
	if (FAILED(result))
	{
		return "swapchain interval quater test failed to initialise\n";
	}

	unit.initialise(device, window);
	unit.bind(context);
	unit.setQuater();

	if (framerate() < 40)
	{
		return std::string();
	}

	return "swapchain interval quater test failed\n";
}

LRESULT CALLBACK SwapchainIntervalQuaterTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

void SwapchainIntervalQuaterTest::cleanup(IUnknown* input)
{
	if (input)
	{
		input->Release();
	}
}

void SwapchainIntervalQuaterTest::initialiseWindowClass()
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

void SwapchainIntervalQuaterTest::initialiseWindow()
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

void SwapchainIntervalQuaterTest::initialiseD3D11()
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

int SwapchainIntervalQuaterTest::framerate()
{
	int output = 0;
	double elapced = 0.0f;
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

	while (elapced < 1.0f)
	{
		unit.update(context);
		elapced += (float)std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
		start = std::chrono::high_resolution_clock::now();
		output++;
	}

	return output;
}
