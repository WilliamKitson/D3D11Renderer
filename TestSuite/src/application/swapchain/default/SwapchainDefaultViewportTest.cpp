#include "SwapchainDefaultViewportTest.h"

SwapchainDefaultViewportTest::SwapchainDefaultViewportTest(HINSTANCE hInstanceInput, int nCmdShowInput)
	: hInstance{ hInstanceInput }, nCmdShow{ nCmdShowInput }, window(), device{nullptr}, context{nullptr}
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
	const wchar_t tag[] = L"swapchain default viewport D3D11";

	WNDCLASS windowClass = WNDCLASS();
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = tag;

	if (!RegisterClass(&windowClass))
	{
		return "swapchain default viewport window class failed to initialise\n";
	}

	window = CreateWindow(
		tag,
		tag,
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
		return "swapchain default viewport window failed to initialise\n";
	}

	ShowWindow(
		window,
		nCmdShow
	);

	D3D_FEATURE_LEVEL levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	D3D_FEATURE_LEVEL supported;

	HRESULT result = D3D11CreateDevice(
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
		return "swapchain default viewport D3D11 failed to initialise\n";
	}

	D3D11Renderer::Swapchain unit;

	unit.initialise(device, window);
	unit.bind(context);

	UINT count = 1;
	D3D11_VIEWPORT viewport = D3D11_VIEWPORT();

	context->RSGetViewports(
		&count,
		&viewport
	);

	D3D11_VIEWPORT successful{
		0.0f,
		0.0f,
		960.0f,
		540.0f,
		0.0f,
		1.0f
	};

	if (viewport == successful)
	{
		return std::string();
	}

	return "swapchain default viewport test failed\n";
}

LRESULT CALLBACK SwapchainDefaultViewportTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}
